#include <iostream>
#include <vector>
#include <allegro5/allegro_primitives.h>
using namespace std;
class snow {
private:
	int Xpos;
	int Ypos;
	int size;

public:

	void repos();
	void draw();
	void movment();
	snow();
};
class snow2 {
private:
	int Xpos;
	int Ypos;
	int size;


public:

	void repos();
	void draw();
	void movment();

	snow2();

};
int main() {
	ALLEGRO_DISPLAY* nomnom;
	srand(time(NULL));
	al_init();
	nomnom = al_create_display(640, 480);
	al_init_primitives_addon();

	vector<snow*>snowcloud;
	vector<snow*>::iterator iter3;
	vector<snow2*>snowcloud2;
	vector<snow2*>::iterator iter2;

	for (int T = 0; T < 500; T++) {
		snow* newsnow = new snow();
		snowcloud.push_back(newsnow);
		snow2* newsnow2 = new snow2();
		snowcloud2.push_back(newsnow2);
	}


	while (1) 
	{
		//"timer" section
		for (iter3 = snowcloud.begin(); iter3 != snowcloud.end(); iter3++){
		(*iter3)-> repos();
		(*iter3)-> movment();

		}


		for (iter2 = snowcloud2.begin(); iter2 != snowcloud2.end(); iter2++) {
			(*iter2)->repos();
			(*iter2)->movment();

		}



		
		
		//"render" section
		al_clear_to_color(al_map_rgb(0, 25, 51));
		for (iter3 = snowcloud.begin(); iter3 != snowcloud.end(); iter3++) {
		(*iter3)->draw();
		}
		for (iter2 = snowcloud2.begin(); iter2 != snowcloud2.end(); iter2++) {
			(*iter2)->draw();
		}
	
	

		al_flip_display();
	}

	system("pause");

	al_destroy_display(nomnom);
	return 0;
}
snow::snow() {
	Xpos = rand() % 480 + 1;
	Ypos = rand() % 640 + 1;
	size = rand() % 2 + 1;
}
snow2::snow2() {
	Xpos = rand() % 480 + 1;
	Ypos = rand() % 640 + 1;
	size = rand() % 8 + 1;
}
void snow::repos() {
	if (Ypos > 640) {
		Xpos = rand() % 604 + 1;
		Ypos = 0;
		size = rand() % 2 + 1;
	}

}
void snow2::repos(){
	if (Ypos > 640) {
		Xpos = rand() % 604 + 1;
		Ypos = 0;
		size = rand() % 2 + 1;
	}

}
void snow::movment() {
	Ypos += 1;

}
void snow2::movment() {
	Ypos += 2;

}

void snow::draw() {
	al_draw_filled_circle(Xpos, Ypos, size, al_map_rgb(255, 255, 255));

}

void snow2::draw() {
	al_draw_filled_circle(Xpos, Ypos, size, al_map_rgb(204, 0, 102));


}