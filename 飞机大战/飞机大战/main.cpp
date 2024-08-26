#include<stdio.h>
#include<easyx.h>
#include"tools.h"
#include<time.h>
IMAGE bk;
IMAGE img_role[2];
IMAGE img_bull[2];
IMAGE img_enemy[2][2];

enum My
{
	WIDTH = 480,
	HEIGHT = 850,
	BULLET_NUM = 30,
	BIG,
	SMALL,
	ENEMY_NUM = 10
};
struct Plane
{
	int x, y;
	bool live;
	int width;
	int height;
	int hp;
	int type;

}player, bull[BULLET_NUM], enemy[ENEMY_NUM];
void enemyHP(int i) {

	if (rand()%8)
	{
		enemy[i].type = SMALL;
		enemy[i].hp = 1;
		enemy[i].height = 20;
		enemy[i].width = 30;
	}
	else {
		enemy[i].type = BIG;
		enemy[i].hp = 1;
		enemy[i].height = 10;
		enemy[i].width = 20;
	}
}





void loadImg()
{
	loadimage(&bk, "images/background.png");
	loadimage(&img_role[0], "images/me1.png");
	loadimage(&img_role[1], "images/me2.png");
	loadimage(&img_bull[0], "images/bullet2.png");
	loadimage(&img_bull[1], "images/bullet2.png");

	loadimage(&img_enemy[0][0], "images/enemy2.png");
	loadimage(&img_enemy[0][1], "images/enemy2.png");
	loadimage(&img_enemy[1][0], "images/enemy3_n1.png");
	loadimage(&img_enemy[1][1], "images/enemy3_n1.png");
}//贴图，初始化图形
void playPlance() {


	for (int i = 0;i < ENEMY_NUM;i++)
	{

		if (!enemy[i].live)
		{
			continue;
		}


		for (int k = 0;k < ENEMY_NUM;k++)
		{
			static DWORD t1, t2;
			if (bull[k].x > enemy[i].x && bull[k].x<enemy[i].x + enemy[i].width
				&& bull[k].y>enemy[i].y && bull[k].y < enemy[i].y + enemy[i].height
				&&t2-t1>50)
			{
				bull[i].live = false;
				enemy[i].hp--;
				t2 = t1;
			}
			if (enemy[i].hp <= 0)
			{
				enemy[i].live = false;
			}
			t2 = GetTickCount();
		}
		enemy[i].hp = 1;

	}

}//打飞机
void gameInit()
{
	player.x = WIDTH / 2;
	player.y = HEIGHT - 360;
	
	player.live = true;

	for (int i = 0;i < BULLET_NUM;i++)
	{
		bull[i].x=0;
	
		bull[i].y = 0;
		bull[i].y = false;
	}
	for (int i = 0;i < ENEMY_NUM;i++)
	{
		
		enemy[i].live = false;
		enemyHP(i);
	}
	


}//初始化
void gameDraw()//显示效果（敌机、飞机、子弹）
{
	loadImg();
	putimage(0, 0, &bk);
	Tools::putimage_alpha(player.x, player.y, &img_role[0]);
	Tools::putimage_alpha(player.x, player.y, &img_role[1]);
	for (int i = 0;i < BULLET_NUM;i++)
	{
		if (bull[i].live) {

			Tools::putimage_alpha(bull[i].x, bull[i].y, &img_bull[0]);
			Tools::putimage_alpha(bull[i].x, bull[i].y, &img_bull[1]);
		}
	}
	for (int i = 0;i < ENEMY_NUM;i++)
	{
		if (enemy[i].live)
		{
			if (enemy[i].type== BIG)
			{
				Tools::putimage_alpha(enemy[i].x, enemy[i].y, &img_enemy[1][0]);
				Tools::putimage_alpha(enemy[i].x, enemy[i].y, &img_enemy[1][1]);
			}
			else
			{
				Tools::putimage_alpha(enemy[i].x, enemy[i].y, &img_enemy[0][0]);
				Tools::putimage_alpha(enemy[i].x, enemy[i].y, &img_enemy[0][1]);
			}
		}
	}
	
}//
void createEnemy() {
	for(int i=0;i<ENEMY_NUM;i++)
		if (!enemy[i].live)
		{
			
			enemy[i].live = true;
			enemy[i].x = rand() % (WIDTH - 30);
			enemy[i].y = 0;
			break;
		}
}
void createBullet()
{
	for (int i = 0;i < BULLET_NUM;i++)
	{
		if (!bull[i].live)
		{
			bull[i].x = player.x +20;
			bull[i].y = player.y;
			bull[i].live = true;
			break;
		}
	}
}
void enemyMove(int speed)
{
	for(int i=0;i<ENEMY_NUM;i++)
		if (enemy[i].live)
		{
			enemy[i].y += speed;
			if (enemy[i].y > HEIGHT)
			{
				enemy[i].live = false;
			}
		}
}
void bulletMove()
{
	for (int i = 0;i < BULLET_NUM;i++)
	{
		if (bull[i].live = true)
		{
			bull[i].y -= 2;
			if (bull[i].y < 0)
			{
				bull[i].live = false;
			}
		}
	}
}
void playerMove(int speed) {
	if (GetAsyncKeyState(VK_UP)) {

		if(player.y>0)
		player.y -= speed;
	}
	if (GetAsyncKeyState(VK_DOWN)) {
		if (player.y <HEIGHT-360)
		player.y += speed;
	}
	if (GetAsyncKeyState(VK_LEFT)) {
		if (player.x >-70)
		player.x -= speed;
	}
	if (GetAsyncKeyState(VK_RIGHT)) {
		if (player.x < WIDTH-40)
		player.x += speed;
	}
	static DWORD t1 = 0, t2 = 0;
	if (GetAsyncKeyState(VK_SPACE)&& t2-t1>50) {
		
		createBullet();
		t1 = t2;
	}
	t2 = GetTickCount();

}
bool Timer(int ms, int id)
{
	static DWORD t[10];
	if (clock() - t[id] > ms)
	{
		t[id] = clock();
		return true;
	}
	return false;
}//计时器，飞机依次出现



int main()
{

	initgraph(WIDTH, HEIGHT);
	
	gameInit();

	BeginBatchDraw();
	while (true)
	{
		gameDraw();
		FlushBatchDraw();
		playerMove(1);
		bulletMove();
		if (Timer(500, 0))
		{


			createEnemy();
		}

		enemyMove(2);
		playPlance();
	}
	
	return 0;
}

