#include<iostream>
#include<thread>
#include<mutex> //Ëø
#include<atomic> //Ô­×Ó
using namespace std;

mutex m;
atomic<int> sum = 0;

void workFun(int index)
{
	//lock_guard<mutex> lg(m); //×Ô½âËø£¬´ÓÉêÃ÷´¦¿ªÊ¼¼ÓËø£¬ÍË³ö×÷ÓÃÓòºó×Ô¶¯½âËø
	//m.lock(); //ÁÙ½çÇø
	sum++;
	//m.unlock();
	cout << "sum=" <<sum<< endl;
}

int main() //mainº¯Êý»á±»Ä¬ÈÏµ±×÷µ±Ç°³ÌÐòµÄÖ÷Ïß³Ì
{
	thread* t[3];
	for (int n = 0; n < 3; n++)
	{
		t[n] = new thread(workFun, n);
		(*t[n]).detach();
	}
	//t.detach(); //Ö÷Ïß³ÌÓë×ÓÏß³ÌÏß³Ì·ÖÀëÖ´ÐÐ£¬µ«ÊÇµ±Ö÷Ïß³Ì½áÊø£¬×ÓÏß³ÌÒ²»á±»ÆÈ½áÊø
	//t.join(); //×ÓÏß³ÌÖ´ÐÐ½áÊøÖ®ºó²Å·µ»ØÖ÷Ïß³Ì¼ÌÐøÖ´ÐÐ£¬¼´Ö÷Ïß³Ì±»×èÈû£»µ«ÊÇ´´½¨³öÀ´µÄ¶à¸ö×ÓÏß³ÌÖ®¼äÊÇ¿ÉÒÔ²¢ÐÐÖ´ÐÐµÄ
	cout << "Hello, I'm main thread"<<endl;
	return 0;
}