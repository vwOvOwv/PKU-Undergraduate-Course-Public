/*˼·����
* �������ڽ������к�˾���Ϊ��Ϸ���е�ɳ��
* ˾�������ʿ����ʿӵ������
* ˾�ͨ��������ʿ����ɳ�̣��Ӷ���������к���ʿ֮�����ϵ���Ӷ�����ͨ���������в���������ʿ����ӵ�е�����
* ֮��Ը������̽���ģ�⣬����ʵ��ħ������
*/
#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<iomanip>
#include<algorithm>
#include<stdio.h>
#include<string>
using namespace std;

class Warrior;
class Weapon;
class Headquarter;
class World;
class City;
class Dragon;
class Ninja;
class Iceman;
class Wolf;
class Lion;

//ħ������ ����˾������
class World {
public:
	Headquarter* Red;
	Headquarter* Blue;
	vector<City*>myCity;
	void run(int);//��Ϸ����
	void lion_escape(int);//5�����жϸ����е�ʨ���Ƿ�����
	void warrior_march(int);//10����������ʿǰ��
	void city_add_element(int);//20���Ӹ����в�������Ԫ
	void get_city_element(int);//30����ʱ˾���ȡ����������Ԫ
	void arrow_attack(int);//35�����жϸ�������ʿ�Ƿ�ż�
	void warrior_judge_bomb(int);//38�����жϸ�������ʿ�Ƿ���ը��
	void warrior_battle(int);//40���ӵ�ս�����̣���Ϊս��ǰϦ��ս���к�ս��������
	void lion_update_init_blood();//ս����ʼǰ�������е�ʨ�Ӹ��³�ʼѪ������¼
	void battle_on(int t);//������ս������
	void after_battle(int t);//ս����������β����
	void clear_up();//ս������������ս��
	void report_element(int);//50����˾���������Ԫ����
	void warrior_report_weapon(int);//55���Ӹ�������ʿ�����������
	World(Headquarter* _Red, Headquarter* _Blue) :Red(_Red), Blue(_Blue) {}
};
//���� ����սʿ��ս������Լ�����������Ԫ
class City {
public:
	string win;//��¼�ó��б���ս����ʤ�����
	int ele;//��¼����Ԫ
	string flag;//������ɫ
	int cnt_red_win;//�췽��ʤ����
	int cnt_blue_win;//������ʤ����
	Warrior* red;//�ó��еĺ췽��ʿ
	Warrior* blue;//�ó��е�������ʿ
	City() {
		win = '\0';//δ����ս����Ϊ��
		red = nullptr;
		blue = nullptr;//����ʿ��Ϊ��
		cnt_red_win = 0;
		cnt_blue_win = 0;
		flag = '\0';//û�����ļ�Ϊ��
		ele = 0;
	}
};
//˾� ����������ʿ
class Headquarter {
public:
	Headquarter* enemy_Headquarter;//�з�˾�
	City* position;//�������е�λ�ã�ͨ����ָ�뽫���ɵ���ʿ��������
	int tmp_element;//��ʱ������ʿͨ��ս��Ϊ˾��ᵽ������Ԫ(�Ƚ�����ʿ����ȡ����Ԫ)
	int element;//���µ�����Ԫ
	int now_id;//������սʿ����
	int cityNo;//����λ�ñ��
	string color;//��Ӫ��ɫ
	bool conquered;//��¼�Ƿ�ռ��
	Headquarter(int _element,string _color,int _cityNo):
		element(_element),color(_color),cityNo(_cityNo),now_id(0),conquered(false),tmp_element(0),position(nullptr),enemy_Headquarter(nullptr){}
	void warrior_born(int);//������ʿ
};
//սʿ�� ��Ϊ������ʿ�Ļ���
class Warrior{
public:
	vector<Weapon*>weapons;//������
	Headquarter*part;//������Ӫ
	string name;//���ƣ��Դ��ж���ʿ����
	int id;//���
	int cityNo;//���ڳ���λ��
	int blood;//Ѫ��
	int force;//������
	void get_weapon();//���ݱ�ź����Եõ�����
	virtual void march();//ǰ��һ����iceman�������ǰ����ʽ
	virtual void born_report();//��˾����ɺ󱨸������Ϣ����ͬ������ʿ�������ݲ�ͬ
	void sort_weapon();//���Լ����������ֵ����ź��򣬱�������������
	void attack(Warrior*, int);//������������
	void fight_back(Warrior*, int);//����
	void win(Warrior*,int);//սʤ�Է���������˴���
	void killed(int);//��ɱ����������
	void even();//�͵��˴�ƽ��������˴���
	void judge_yell(int t);//�ж��Ƿ���dragon�Լ��Ƿ���Ҫ����
	Warrior(int _blood, int _force, Headquarter* _part, string _name):blood(_blood), force(_force), part(_part), id(part->now_id), cityNo(part->cityNo), name(_name) {
		weapons.push_back(nullptr);//��ʼ��Ϊһ����ָ�룬�������vectorΪ�յ�����Խ�����
	}
};
class Dragon :public Warrior {
public:
	static int mem_blood;//�����dragonѪ��
	static int mem_force;//�����dragon������
	double morale;//ʿ��
	Dragon(int _blood,int _force,Headquarter*part,string _name):Warrior(_blood, _force, part,_name){
		part->element -= blood;//����ʱ˾�����Ԫ����
		morale = double(part->element) / blood;//Ҫ�ñ仯���˾�����Ԫ
	}
	void yell(int);//����
	virtual void born_report();//dragon������ʱ��Ҫ����ʿ����ʼֵ
};
class Ninja :public Warrior {
public:
	static int mem_blood;//�����ninjaѪ��
	static int mem_force;//�����ninja������
	Ninja(int _blood, int _force, Headquarter* part,string _name) :Warrior(_blood, _force, part,_name) {
		part->element -= blood;//����ʱ˾�����Ԫ����
	}
};
class Iceman :public Warrior {
public:
	static int mem_blood;//�����icemanѪ��
	static int mem_force;//�����iceman������
	int cnt_march;//ǰ��������¼
	Iceman(int _blood, int _force, Headquarter* part,string _name) :Warrior(_blood, _force, part, _name),cnt_march(0) {
		part->element -= blood;
	}
	virtual void march();//icemanǰ��������Ѫ���빥�������ܸı�
};
class Lion :public Warrior {
public:
	static int mem_blood;//�����lionѪ��
	static int mem_force;//�����lion������
	static int lion_k;//�����lion�ҳ϶��½�ֵ
	int loyalty;//�ҳ϶�
	int init_blood;//ÿСʱս����ʼǰ��ʼѪ����¼
	Lion(int _blood, int _force, Headquarter* part,string _name) :Warrior(_blood, _force, part,_name),init_blood(_blood){
		part->element -= _blood;
		loyalty = part->element;//�ҳ϶ȵ��ڱ仯���˾�����Ԫ
	}
	void update_init_blood();//���³�ʼѪ��
	void blood_trans(Warrior*);//��ս������Լ��ĳ�ʼѪ��ת�Ƹ�����
	virtual void born_report();//������ʱҪ�����ʼ�ҳ϶�
};
class Wolf :public Warrior {
public:
	static int mem_blood;//�����wolfѪ��
	static int mem_force;//�����wolf������
	Wolf(int _blood, int _force, Headquarter* part,string _name) :Warrior(_blood, _force, part,_name) {
		part->element -= blood;
	}
	void get_enemy_weapon(Warrior*);//սʤ֮��Ҫ�ɻ��������
};
//������ ��Ϊ���������Ļ���
class Weapon {
public:
	string name;//���ƣ��Դ��ж���������
	Warrior* master;//ӵ����
	int weapon_force;//����������
	Weapon(int k, Warrior* _master, string _name) :weapon_force(k), master(_master), name(_name) {}
	virtual void attack(Warrior*, int);//�������ˣ���ͬ����������ʽ��ͬ
	virtual void lost();//��������
};
class Arrow :public Weapon {
public:
	static int arrow_r;//�����arrow�Ĺ�����
	int use_cnt = 0;//ʹ�ô�������
	virtual void attack(Warrior*, int);//��������
	Arrow(Warrior*_master,string _name):Weapon(arrow_r,_master,_name){}
};
class Bomb :public Weapon {
public:
	virtual void attack(Warrior*,int);//��������
	Bomb(Warrior*_master,string _name):Weapon(INT_MAX,_master,_name){}//Bomb�޹������ĸ������ɱ��˫�����ʳ�ʼ��������Ϊ���޴�
};
class Sword:public Weapon {
public:
	Sword(Warrior* _master, string _name):Weapon(_master->force*2/10,_master,_name) {}
};

int Dragon::mem_blood = 0;
int Dragon::mem_force = 0;
int Ninja::mem_blood = 0;
int Ninja::mem_force = 0;
int Iceman::mem_blood = 0;
int Iceman::mem_force = 0;
int Lion::mem_blood = 0;
int Lion::mem_force = 0;
int Lion::lion_k = 0;
int Wolf::mem_blood = 0;
int Wolf::mem_force = 0;
int Arrow::arrow_r = 0;

int get_hour(int t) { return t / 60; }//��ȡ��ǰСʱ��
int get_minute(int t) { return t % 60; }//��ȡ��ǰ������
void output_time(int t) { cout << setw(3) << setfill('0') << get_hour(t) << ':' << setw(2) << setfill('0') << get_minute(t); }//�����ǰʱ��
bool Compare(const Weapon* x1, const Weapon* x2)
{
	if (x1->name < x2->name)
		return true;
	else
		return false;
}//������������������򡪡����ֵ�������
vector<Weapon*>new_weapon_to_delete;
vector<Warrior*>new_warrior_to_delete;

void World::run(int T) {
	int time_in_minute = 0;//��¼�Է���Ϊ��λ��ʱ��
	while (1) {
		if (time_in_minute > T)//����ʱ�����ƣ���Ϸ����
			break;
		int time_remain = time_in_minute % 60;//��Сʱ�ķ�����
		switch (time_remain)
		{
		case 0:
			Red->warrior_born(time_in_minute);
			Blue->warrior_born(time_in_minute);
			break;
		case 5:
			lion_escape(time_in_minute);
			break;
		case 10:
			warrior_march(time_in_minute);
			if (Red->conquered || Blue->conquered)//��ʿǰ�������ռ��з�˾�����Ҫ�ж�
				return;
			break;
		case 20:
			city_add_element(time_in_minute);
			break;
		case 30:
			get_city_element(time_in_minute);
			break;
		case 35:
			arrow_attack(time_in_minute);
			break;
		case 38:
			warrior_judge_bomb(time_in_minute);
			break;
		case 40:
			warrior_battle(time_in_minute);
			break;
		case 50:
			report_element(time_in_minute);
			break;
		case 55:
			warrior_report_weapon(time_in_minute);
			break;
		}
		//ʱ�����
		if (time_remain == 35)
			time_in_minute += 3;
		else if (time_remain == 38)
			time_in_minute += 2;
		else
			time_in_minute += 5;
	}
}
void World::lion_escape(int t) {
	auto i = myCity.begin();
	for (; i != myCity.end(); ++i) {
		if ((*i)->red != nullptr && (*i)->red->name == "lion" && (*i)->red->cityNo != Blue->cityNo) {//�ִ�з�˾���lion��������
			auto j = (Lion*)((*i)->red);
			if (j->loyalty <= 0) {
				output_time(t);
				cout << ' ' << "red lion " << (*i)->red->id << " ran away" << endl;
				(*i)->red = nullptr;
			}
		}
		if ((*i)->blue != nullptr && (*i)->blue->name == "lion" && (*i)->blue->cityNo != Red->cityNo) {//�ִ�з�˾���lion��������
			auto j = (Lion*)((*i)->blue);
			if (j->loyalty <= 0) {
				output_time(t);
				cout << ' ' << "blue lion " << (*i)->blue->id << " ran away" << endl;
				(*i)->blue = nullptr;
			}
		}
	}
}
void World::warrior_march(int t) {//�¼���������ʿǰ����Ŀ�ĵ�
	auto i = myCity.begin();
	for (; i != myCity.end(); ++i) {
		if (i > myCity.begin() && (*(i - 1))->red != nullptr) {
			if ((*(i - 1))->red->cityNo != (*(i - 1))->red->part->enemy_Headquarter->cityNo) {//δ����з�˾�
				(*(i - 1))->red->march();
				if ((*(i - 1))->red->cityNo == (*(i - 1))->red->part->enemy_Headquarter->cityNo) {//ǰ���󵽴�з�˾�
					output_time(t);
					cout << " red " << (*(i - 1))->red->name << ' '
						<< (*(i - 1))->red->id << " reached blue headquarter with " << (*(i - 1))->red->blood
						<< " elements and force " << (*(i - 1))->red->force << endl;
					(*i)->cnt_red_win++;//����˾���սʿ����
					if ((*i)->cnt_red_win == 2) {//ռ��з�˾�
						Blue->conquered = true;
						output_time(t);
						cout << " blue headquarter was taken" << endl;
					}
				}
				else {//ǰ������δ����з�˾�
					output_time(t);
					cout << " red " << (*(i - 1))->red->name << ' '
						<< (*(i - 1))->red->id << " marched to city " << (*(i - 1))->red->cityNo << " with " << (*(i - 1))->red->blood <<
						" elements and force " << (*(i - 1))->red->force << endl;
				}
			}
		}
		if (i < --myCity.end() && (*(i + 1))->blue != nullptr) {
			if ((*(i + 1))->blue->cityNo != (*(i + 1))->blue->part->enemy_Headquarter->cityNo) {//δ����з�˾�
				(*(i + 1))->blue->march();
				if ((*(i + 1))->blue->cityNo == (*(i + 1))->blue->part->enemy_Headquarter->cityNo) {//ǰ���󵽴�з�˾�
					output_time(t);
					cout << " blue " << (*(i + 1))->blue->name << ' '
						<< (*(i + 1))->blue->id << " reached red headquarter with " << (*(i + 1))->blue->blood
						<< " elements and force " << (*(i + 1))->blue->force << endl;
					(*i)->cnt_blue_win++;//����˾���սʿ����
					if ((*i)->cnt_blue_win == 2) {//ռ��з�˾�
						Red->conquered = true;
						output_time(t);
						cout << " red headquarter was taken" << endl;
					}
				}
				else {
					output_time(t);
					cout << " blue " << (*(i + 1))->blue->name << ' '
						<< (*(i + 1))->blue->id << " marched to city " << (*(i + 1))->blue->cityNo << " with " << (*(i + 1))->blue->blood <<
						" elements and force " << (*(i + 1))->blue->force << endl;
				}
			}
		}
	}
	i = --myCity.end();
	for (; i != myCity.begin(); --i) {
		if ((*(i - 1))->red != nullptr) {
			(*i)->red = (*(i - 1))->red;
			(*(i - 1))->red = nullptr;
		}
	}
	i = myCity.begin();
	for (; i != --myCity.end(); ++i) {
		if ((*(i + 1))->blue != nullptr) {
			(*i)->blue = (*(i + 1))->blue;
			(*(i + 1))->blue = nullptr;
		}
	}
}
void World::city_add_element(int t) {
	auto i = myCity.begin() + 1;
	for (; i != myCity.end() - 1; ++i) {//˾�����������Ԫ
		(*i)->ele += 10;
	}
}
void World::get_city_element(int t) {
	auto i = myCity.begin() + 1;
	for (; i != myCity.end() - 1; ++i) {
		if ((*i)->red != nullptr && (*i)->blue == nullptr) {//ֻ�к췽��ʿ�ڸó���
			Red->element += (*i)->ele;
			output_time(t);
			cout << " red " << (*i)->red->name << ' ' << (*i)->red->id << " earned " << (*i)->ele << " elements for his headquarter" << endl;
			(*i)->ele = 0;
		}
		if ((*i)->red == nullptr && (*i)->blue != nullptr) {//ֻ��������ʿ�ڸó���
			Blue->element += (*i)->ele;
			output_time(t);
			cout << " blue " << (*i)->blue->name << ' ' << (*i)->blue->id << " earned " << (*i)->ele << " elements for his headquarter" << endl;
			(*i)->ele = 0;
		}
	}
}
void World::arrow_attack(int t) {
	auto i = myCity.begin();
	for (; i != myCity.end(); ++i) {
		if (i < myCity.end() - 2 && (*i)->red != nullptr && (*(i + 1))->blue != nullptr) {//������з�˾��ż�
			auto j = (*i)->red->weapons.begin();
			for (; j != (*i)->red->weapons.end(); ++j) {
				if ((*j)!=nullptr&&(*j)->name == "arrow") {//����arrow
					(*j)->attack((*(i + 1))->blue, t);
					break;
				}
			}
		}
		if (i > myCity.begin() + 1 && (*i)->blue != nullptr && (*(i - 1))->red != nullptr) {//������з�˾��ż�
			auto j = (*i)->blue->weapons.begin();
			for (; j != (*i)->blue->weapons.end(); ++j) {
				if ((*j)!=nullptr&&(*j)->name == "arrow") {//����arrow
					(*j)->attack((*(i - 1))->red, t);
					break;
				}
			}
		}
	}
}
void World::warrior_judge_bomb(int t) {
	auto i = myCity.begin() + 1;
	for (; i < myCity.end() - 1; ++i) {//˾����ᷢ��ս��
		if ((*i)->red != nullptr && (*i)->blue != nullptr && (*i)->red->blood > 0 && (*i)->blue->blood > 0) {//�ó�����40���ӻᷢ��ս��
			int red_force = (*i)->red->force;//�췽��������������
			int red_back_force = (*i)->red->force / 2;//�췽����������
			int blue_force = (*i)->blue->force;//������������������
			int blue_back_force = (*i)->blue->force / 2;//��������������
			auto j1 = (*i)->red->weapons.begin();
			auto j2 = (*i)->blue->weapons.begin();
			for (; j1 != (*i)->red->weapons.end(); ++j1) {//����sword
				if ((*j1) != nullptr && (*j1)->name == "sword") {//�������sword������
					red_force += (*j1)->weapon_force;
					red_back_force += (*j1)->weapon_force;
				}
			}
			for (; j2 != (*i)->blue->weapons.end(); ++j2) {//����sword
				if ((*j2) != nullptr && (*j2)->name == "sword") {//�������sword������
					blue_force += (*j2)->weapon_force;
					blue_back_force += (*j2)->weapon_force;
				}
			}
			int pos = (*i)->red->cityNo;//��ȡ����λ��
			if ((pos % 2 == 1 && (*i)->flag[0] == '\0') || (*i)->flag == "red") {//�췽����
				j1 = (*i)->red->weapons.begin();
				j2 = (*i)->blue->weapons.begin();
				for (; j1 != (*i)->red->weapons.end(); ++j1) {//����bomb
					if ((*j1) != nullptr && (*j1)->name == "bomb") {//��bomb
						if (red_force < (*i)->blue->blood && blue_back_force >= (*i)->red->blood && (*i)->blue->name != "ninja") {//������������ը��(ninja������)
							(*j1)->attack((*i)->blue, t);
							(*i)->blue = nullptr;
							(*i)->red = nullptr;
							break;
						}
					}
				}
				if ((*i)->blue != nullptr)//�췽û��ը��
					for (; j2 != (*i)->blue->weapons.end(); ++j2) {//����bomb
						if ((*j2) != nullptr && (*j2)->name == "bomb") {//��bomb
							if (red_force >= (*i)->blue->blood) {//����������������ը��
								(*j2)->attack((*i)->red, t);
								(*i)->blue = nullptr;
								(*i)->red = nullptr;
								break;
							}
						}
					}
			}
			if ((pos % 2 == 0 && (*i)->flag[0] == '\0') || (*i)->flag == "blue") {//��������
				j1 = (*i)->red->weapons.begin();
				j2 = (*i)->blue->weapons.begin();
				for (; j2 != (*i)->blue->weapons.end(); ++j2) {//����bomb
					if ((*j2) != nullptr && (*j2)->name == "bomb") {//��bomb
						if (blue_force < (*i)->red->blood && red_back_force >= (*i)->blue->blood && (*i)->red->name != "ninja") {//������������ը��(ninja������)
							(*j2)->attack((*i)->red, t);
							(*i)->blue = nullptr;
							(*i)->red = nullptr;
							break;
						}
					}
				}
				if ((*i)->blue != nullptr)
					for (; j1 != (*i)->red->weapons.end(); ++j1) {//����bomb
						if ((*j1) != nullptr && (*j1)->name == "bomb") {//��bomb
							if (blue_force >= (*i)->red->blood) {//����������������ը��
								(*j1)->attack((*i)->blue, t);
								(*i)->blue = nullptr;
								(*i)->red = nullptr;
								break;
							}
						}
					}
			}
		}
	}
}
void World::warrior_battle(int t) {
	lion_update_init_blood();
	battle_on(t);
	after_battle(t);
}
void World::lion_update_init_blood() {
	auto i = myCity.begin() + 1;
	for (; i != myCity.end() - 1; ++i) {//˾���ս�������ø���Ѫ��
		if ((*i)->blue != nullptr && (*i)->blue->name == "lion") {
			Lion* k = (Lion*)((*i)->blue);
			k->update_init_blood();
		}
		if ((*i)->red != nullptr && (*i)->red->name == "lion") {
			Lion* k = (Lion*)((*i)->red);
			k->update_init_blood();
		}
	}
}
void World::battle_on(int t) {//�������п������
	auto i = myCity.begin() + 1;
	for (; i != myCity.end() - 1; ++i) {//˾����ᷢ��ս��
		if ((*i)->red != nullptr && (*i)->blue != nullptr) {//����ʿ�Ҷ����Ǳ�ը����
			if ((*i)->red->blood <= 0 && (*i)->blue->blood <= 0) {}//�����������ˣ�����ս�������·���
			else if ((*i)->red->blood <= 0 && (*i)->blue->blood > 0) {//�췽��ʿ����������������ʿ������ʤ
				(*i)->blue->win((*i)->red, t);
				if (((*i)->flag[0] == '\0' && (*i)->blue->cityNo % 2 == 0) || (*i)->flag == "blue")//�������֣����ܻ���
					(*i)->blue->judge_yell(t);
				if ((*i)->ele > 0) {//�ó���������Ԫ���ȡ
					output_time(t);
					cout << " blue " << (*i)->blue->name << ' ' << (*i)->blue->id << " earned " << (*i)->ele << " elements for his headquarter" << endl;
					Blue->tmp_element += (*i)->ele;
					(*i)->ele = 0;
				}
				(*i)->cnt_blue_win++;
				(*i)->cnt_red_win = 0;
				(*i)->win = "blue";
				if ((*i)->cnt_blue_win % 2 == 0 && (*i)->flag != "blue") {//��������
					(*i)->flag = "blue";
					output_time(t);
					cout << " blue flag raised in city " << (*i)->blue->cityNo << endl;
				}
			}
			else if ((*i)->red->blood > 0 && (*i)->blue->blood <= 0) {//������ʿ�����������췽��ʿ���췽ʤ
				(*i)->red->win((*i)->blue, t);
				if (((*i)->flag[0] == '\0' && (*i)->red->cityNo % 2 == 1) || (*i)->flag == "red")//�췽���֣����ܻ���
					(*i)->red->judge_yell(t);
				if ((*i)->ele > 0) {//�ó���������Ԫ���ȡ
					output_time(t);
					cout << " red " << (*i)->red->name << ' ' << (*i)->red->id << " earned " << (*i)->ele << " elements for his headquarter" << endl;
					Red->tmp_element += (*i)->ele;
					(*i)->ele = 0;
				}
				(*i)->cnt_red_win++;
				(*i)->cnt_blue_win = 0;
				(*i)->win = "red";
				if ((*i)->cnt_red_win % 2 == 0 && (*i)->flag != "red") {//��������
					(*i)->flag = "red";
					output_time(t);
					cout << " red flag raised in city " << (*i)->red->cityNo << endl;
				}
			}
			else {//˫��������ʽս��
				int pos = (*i)->blue->cityNo;
				if ((*i)->flag == "red" || ((*i)->flag[0] =='\0' && pos % 2 == 1)) {//�췽����
					(*i)->red->attack((*i)->blue, t);
					if ((*i)->blue->blood <= 0) {//������ɱ����췽ʤ
						(*i)->blue->killed(t);
						(*i)->red->win((*i)->blue, t);
						(*i)->red->judge_yell(t);//�췽���֣����ܻ���
						if ((*i)->ele > 0) {//�ó���������Ԫ���ȡ
							output_time(t);
							cout << " red " << (*i)->red->name << ' ' << (*i)->red->id << " earned " << (*i)->ele << " elements for his headquarter" << endl;
							Red->tmp_element += (*i)->ele;
							(*i)->ele = 0;
						}
						(*i)->cnt_red_win++;
						(*i)->cnt_blue_win = 0;//������ʤ�ж�
						(*i)->win = "red";
						if ((*i)->cnt_red_win % 2 == 0 && (*i)->flag != "red") {//��������
							(*i)->flag = "red";
							output_time(t);
							cout << " red flag raised in city " << (*i)->red->cityNo << endl;
						}
					}
					else {//����û��ɱ�������ܷ���
						if ((*i)->blue->name == "ninja") {//ninja������
							(*i)->red->even();//ƽ��
							(*i)->red->judge_yell(t);//�췽���֣����ܻ���
							(*i)->cnt_blue_win = 0;
							(*i)->cnt_red_win = 0;//˫����ʤ���ж�
							(*i)->win = '\0';//��ʤ��
						}
						else {//��������
							(*i)->blue->fight_back((*i)->red, t);
							if ((*i)->red->blood <= 0) {//�췽��ɱ��
								(*i)->red->killed(t);
								(*i)->blue->win((*i)->red, t);
								if ((*i)->ele > 0) {//�ó���������Ԫ���ȡ
									output_time(t);
									cout << " blue " << (*i)->blue->name << ' ' << (*i)->blue->id << " earned " << (*i)->ele << " elements for his headquarter" << endl;
									Blue->tmp_element += (*i)->ele;
									(*i)->ele = 0;
								}
								(*i)->cnt_blue_win++;
								(*i)->cnt_red_win = 0;//�췽��ʤ�ж�
								(*i)->win = "blue";
								if ((*i)->cnt_blue_win % 2 == 0 && (*i)->flag != "blue") {//��������
									(*i)->flag = "blue";
									output_time(t);
									cout << " blue flag raised in city " << (*i)->blue->cityNo << endl;
								}
							}
							else {
								(*i)->red->even();
								(*i)->blue->even();//ƽ��
								(*i)->red->judge_yell(t);//�췽���֣����ܻ���
								(*i)->cnt_blue_win = 0;
								(*i)->cnt_red_win = 0;//˫����ʤ���ж�
								(*i)->win = '\0';
							}
						}
					}
				}
				else {//��������(������������)
					(*i)->blue->attack((*i)->red, t);
					if ((*i)->red->blood <= 0) {
						(*i)->red->killed(t);
						(*i)->blue->win((*i)->red, t);
						(*i)->blue->judge_yell(t);
						if ((*i)->ele > 0) {
							output_time(t);
							cout << " blue " << (*i)->blue->name << ' ' << (*i)->blue->id << " earned " << (*i)->ele << " elements for his headquarter" << endl;
							Blue->tmp_element += (*i)->ele;
							(*i)->ele = 0;
						}
						(*i)->cnt_blue_win++;
						(*i)->cnt_red_win = 0;
						(*i)->win = "blue";
						if ((*i)->cnt_blue_win % 2 == 0 && (*i)->flag != "blue") {
							(*i)->flag = "blue";
							output_time(t);
							cout << " blue flag raised in city " << (*i)->blue->cityNo << endl;
						}
					}
					else {
						if ((*i)->red->name == "ninja") {
							(*i)->blue->even();
							(*i)->blue->judge_yell(t);
							(*i)->cnt_blue_win = 0;
							(*i)->cnt_red_win = 0;
							(*i)->win = '\0';
						}
						else {
							(*i)->red->fight_back((*i)->blue, t);
							if ((*i)->blue->blood <= 0) {
								(*i)->blue->killed(t);
								(*i)->red->win((*i)->blue, t);
								if ((*i)->ele > 0) {
									output_time(t);
									cout << " red " << (*i)->red->name << ' ' << (*i)->red->id << " earned " << (*i)->ele << " elements for his headquarter" << endl;
									Red->tmp_element += (*i)->ele;
									(*i)->ele = 0;
								}
								(*i)->cnt_red_win++;
								(*i)->cnt_blue_win = 0;
								(*i)->win = "red";
								if ((*i)->cnt_red_win % 2 == 0 && (*i)->flag != "red") {
									(*i)->flag = "red";
									output_time(t);
									cout << " red flag raised in city " << (*i)->red->cityNo << endl;
								}
							}
							else {
								(*i)->red->even();
								(*i)->blue->even();
								(*i)->blue->judge_yell(t);
								(*i)->cnt_blue_win = 0;
								(*i)->cnt_red_win = 0;
								(*i)->win = '\0';
							}
						}
					}
				}
			}
		}
	}
}
void World::after_battle(int t) {
	auto i = myCity.end() - 2;
	for (; i > myCity.begin(); --i) {//�췽�Զ�����������ʿ
		if ((*i)->win == "red") {
			if (Red->element >= 8) {
				Red->element -= 8;
				(*i)->red->blood += 8;
			}
		}
	}
	Red->element += Red->tmp_element;//��ȡ��ʿ��õ�����Ԫ
	Red->tmp_element = 0;
	i = myCity.begin() + 1;
	for (; i < myCity.end() - 1; ++i) {//���������򶫽�����ʿ
		if ((*i)->win == "blue") {
			if (Blue->element >= 8) {
				Blue->element -= 8;
				(*i)->blue->blood += 8;
			}
		}
	}
	Blue->element += Blue->tmp_element;//��ȡ��ʿ��ȡ������Ԫ
	Blue->tmp_element = 0;
	clear_up();//����ս��
}
void World::warrior_report_weapon(int t) {//�����򶫣��Ⱥ����
	auto i = myCity.begin();
	int cnt = 0;
	for (; i != myCity.end(); ++i) {
		if ((*i)->red != nullptr) {
			cnt = 0;//����������ǵڼ�������
			if ((*i)->red->weapons.size() > 1) {//������
				auto j = ++(*i)->red->weapons.begin();
				for (; j != (*i)->red->weapons.end(); ++j) {
					if (cnt == 0) {//֮ǰû�����
						output_time(t);
						cout << " red " << (*i)->red->name << ' ' << (*i)->red->id << " has " << (*j)->name;
						cnt++;
					}
					else {
						cout << ',' << (*j)->name;
					}
					if ((*j)->name == "arrow") {
						Arrow* k = (Arrow*)(*j);
						cout << '(' << 3 - k->use_cnt << ')';//������ô���
					}
					if ((*j)->name == "sword") {
						cout << '(' << (*j)->weapon_force << ')';//���������
					}
				}
				cout << endl;
			}
			else {//û����
				output_time(t);
				cout << " red " << (*i)->red->name << ' ' << (*i)->red->id << " has no weapon" << endl;
			}
		}
	}
	//������������
	i = myCity.begin();
	for (; i != myCity.end(); ++i) {
		if ((*i)->blue != nullptr) {
			cnt = 0;
			if ((*i)->blue->weapons.size() > 1) {
				auto j = ++(*i)->blue->weapons.begin();
				for (; j != (*i)->blue->weapons.end(); ++j) {
					if (cnt == 0) {
						output_time(t);
						cout << " blue " << (*i)->blue->name << ' ' << (*i)->blue->id << " has " << (*j)->name;
						cnt++;
					}
					else {
						cout << ',' << (*j)->name;
					}
					if ((*j)->name == "arrow") {
						Arrow* k = (Arrow*)(*j);
						cout << '(' << 3 - k->use_cnt << ')';
					}
					if ((*j)->name == "sword") {
						cout << '(' << (*j)->weapon_force << ')';
					}
				}
				cout << endl;
			}
			else {
				output_time(t);
				cout << " blue " << (*i)->blue->name << ' ' << (*i)->blue->id << " has no weapon" << endl;
			}
		}
	}
}
void World::clear_up() {
	auto i = myCity.begin()+1;
	for (; i != myCity.end()-1; ++i) {//��ս����սʿָ���ÿ�
		if ((*i)->blue != nullptr && (*i)->blue->blood <= 0)
			(*i)->blue = nullptr;
		if ((*i)->red != nullptr && (*i)->red->blood <= 0)
			(*i)->red = nullptr;
		(*i)->win = '\0';//ʤ�߼�¼�ÿ�
	}
}
void World::report_element(int t) {
	output_time(t);
	cout <<' '<< Red->element << " elements in red headquarter" << endl;
	output_time(t);
	cout <<' '<< Blue->element << " elements in blue headquarter" << endl;
}
void Headquarter::warrior_born(int t) {//˫��������ʿ��˳��ͬ����˷ֿ�����
	if (color == "red") {
		int mod_red = now_id % 5;//������ʿ��˳��
		switch (mod_red)
		{
		case 0:
			if (element >= Iceman::mem_blood) {
				now_id++;
				Warrior* p = new Iceman(Iceman::mem_blood, Iceman::mem_force, this, "iceman");
				new_warrior_to_delete.push_back(p);//new������ָ��Ҫdelete
				p->get_weapon();
				position->red = p;
				output_time(t);
				p->born_report();
			}
			break;
		case 1:
			if (element >= Lion::mem_blood) {
				now_id++;
				Warrior* p = new Lion(Lion::mem_blood, Lion::mem_force, this, "lion");
				new_warrior_to_delete.push_back(p);
				p->get_weapon();
				position->red = p;
				output_time(t);
				p->born_report();
			}
			break;
		case 2:
			if (element >= Wolf::mem_blood) {
				now_id++;
				Warrior* p = new Wolf(Wolf::mem_blood, Wolf::mem_force, this, "wolf");
				new_warrior_to_delete.push_back(p);
				p->get_weapon();
				position->red = p;
				output_time(t);
				p->born_report();
			}
			break;
		case 3:
			if (element >= Ninja::mem_blood) {
				now_id++;
				Warrior* p = new Ninja(Ninja::mem_blood, Ninja::mem_force, this, "ninja");
				new_warrior_to_delete.push_back(p);
				p->get_weapon();
				position->red = p;
				output_time(t);
				p->born_report();
			}
			break;
		case 4:
			if (element >= Dragon::mem_blood) {
				now_id++;
				Warrior* p = new Dragon(Dragon::mem_blood, Dragon::mem_force, this, "dragon");
				new_warrior_to_delete.push_back(p);
				p->get_weapon();
				position->red = p;
				output_time(t);
				p->born_report();
			}
			break;
		}
	}
	else {
		int mod_blue = now_id % 5;//������ʿ��˳��
		switch (mod_blue)
		{
		case 0:
			if (element >= Lion::mem_blood) {
				now_id++;
				Warrior* p = new Lion(Lion::mem_blood, Lion::mem_force, this, "lion");
				new_warrior_to_delete.push_back(p);
				p->get_weapon();
				position->blue = p;
				output_time(t);
				p->born_report();
			}
			break;
		case 1:
			if (element >= Dragon::mem_blood) {
				now_id++;
				Warrior* p = new Dragon(Dragon::mem_blood, Dragon::mem_force, this, "dragon");
				new_warrior_to_delete.push_back(p);
				p->get_weapon();
				position->blue = p;
				output_time(t);
				p->born_report();
			}
			break;
		case 2:
			if (element >= Ninja::mem_blood) {
				now_id++;
				Warrior* p = new Ninja(Ninja::mem_blood, Ninja::mem_force, this, "ninja");
				new_warrior_to_delete.push_back(p);
				p->get_weapon();
				position->blue = p;
				output_time(t);
				p->born_report();
			}
			break;
		case 3:
			if (element >= Iceman::mem_blood) {
				now_id++;
				Warrior* p = new Iceman(Iceman::mem_blood, Iceman::mem_force, this, "iceman");
				new_warrior_to_delete.push_back(p);
				p->get_weapon();
				position->blue = p;
				output_time(t);
				p->born_report();
			}
			break;

		case 4:
			if (element >= Wolf::mem_blood) {
				now_id++;
				Warrior* p = new Wolf(Wolf::mem_blood, Wolf::mem_force, this, "wolf");
				new_warrior_to_delete.push_back(p);
				p->get_weapon();
				position->blue = p;
				output_time(t);
				p->born_report();
			}
			break;
		}
	}
}
void Warrior::get_weapon() {
	int weapon1_id = id % 3;
	int weapon2_id = (id + 1) % 3;//ninja����������
	Weapon* p1;
	Weapon* p2;
	switch (name[0]) {
	case 'd':
		switch (weapon1_id) {
		case 0:
			p1 = new Sword(this, "sword");
			new_weapon_to_delete.push_back(p1);
			if (p1->weapon_force == 0)//sword������Ϊ0��Ϊû��sword
				break;
			weapons.push_back(p1);
			break;
		case 1:
			p1 = new Bomb(this, "bomb");
			new_weapon_to_delete.push_back(p1);
			weapons.push_back(p1);
			break;
		case 2:
			p1 = new Arrow(this, "arrow");
			new_weapon_to_delete.push_back(p1);
			weapons.push_back(p1);
			break;
		}
		break;
	case 'n':
		switch (weapon1_id) {
		case 0:
			p1 = new Sword(this, "sword");
			new_weapon_to_delete.push_back(p1);
			if (p1->weapon_force == 0)//sword������Ϊ0��Ϊû��sword
				break;
			weapons.push_back(p1);
			break;
		case 1:
			p1 = new Bomb(this, "bomb");
			new_weapon_to_delete.push_back(p1);
			weapons.push_back(p1);
			break;
		case 2:
			p1 = new Arrow(this, "arrow");
			new_weapon_to_delete.push_back(p1);
			weapons.push_back(p1);
			break;
		}
		switch (weapon2_id) {
		case 0:
			p2 = new Sword(this, "sword");
			new_weapon_to_delete.push_back(p2);
			if (p2->weapon_force == 0)//sword������Ϊ0��Ϊû��sword
				break;
			weapons.push_back(p2);
			break;
		case 1:
			p2 = new Bomb(this, "bomb");
			new_weapon_to_delete.push_back(p2);
			weapons.push_back(p2);
			break;
		case 2:
			p2 = new Arrow(this, "arrow");
			new_weapon_to_delete.push_back(p2);
			weapons.push_back(p2);
			break;
		}
		break;
	case 'i':
		switch (weapon1_id) {
		case 0:
			p1 = new Sword(this, "sword");
			new_weapon_to_delete.push_back(p1);
			if (p1->weapon_force == 0)//sword������Ϊ0��Ϊû��sword
				break;
			weapons.push_back(p1);
			break;
		case 1:
			p1 = new Bomb(this, "bomb");
			new_weapon_to_delete.push_back(p1);
			weapons.push_back(p1);
			break;
		case 2:
			p1 = new Arrow(this, "arrow");
			new_weapon_to_delete.push_back(p1);

			weapons.push_back(p1);
			break;
		}
		break;
	case 'l':
		break;
	case 'w':
		break;
	}
	sort_weapon();//�����������������
}
void Warrior::march() {
	if (part->color == "red") {
		cityNo++;
	}
	else
		cityNo--;
}
void Warrior::born_report() {
	cout << ' ' << part->color << ' ' << name << ' ' << id << " born" << endl;
}
void Warrior::win(Warrior* enemy, int t) {
	if (name == "dragon") {//dragonսʤʿ������
		Dragon* k = (Dragon*)this;
		k->morale += 0.2;
	}
	if (name == "wolf") {//wolfսʤ�ɻ��������
		Wolf* k = (Wolf*)this;
		k->get_enemy_weapon(enemy);
	}
	if (enemy->name == "lion") {//lionս��ת������ֵ
		Lion* k = (Lion*)enemy;
		k->blood_trans((Lion*)(this));
	}
}
void Warrior::even() {
	if (name == "dragon") {//dragon��ƽʿ���½�
		Dragon* k = (Dragon*)this;
		k->morale -= 0.2;
	}
	if (name == "lion") {//lion��ƽ�ҳ϶��½�
		Lion* k = (Lion*)this;
		k->loyalty -= k->lion_k;
	}
}
void Warrior::killed(int t) {
	output_time(t);
	cout << ' ' << part->color << ' ' << name << ' ' << id << " was killed in city " << cityNo << endl;
}
void Warrior::judge_yell(int t) {
	if (name == "dragon") {
		Dragon* k = (Dragon*)this;
		if (k->morale > 0.8)
			k->yell(t);
	}
}
void Warrior::sort_weapon() {
	if (weapons.size() > 1)//������������
		sort(++weapons.begin(), weapons.end(), Compare);
}
void Warrior::attack(Warrior* enemy, int t) {
	int tmp_force = force;
	auto i = weapons.begin();
	for (; i != weapons.end(); ++i) {
		if ((*i) != nullptr && (*i)->name == "sword") {//��swordҪ����sword�Ĺ�����
			tmp_force += (*i)->weapon_force;
			(*i)->weapon_force = (*i)->weapon_force * 4 / 5;//sword����
			if ((*i)->weapon_force == 0)//sword��������Ϊ������
				(*i)->lost();
			break;
		}
	}
	enemy->blood -= tmp_force;
	output_time(t);
	cout << ' ' << part->color << ' ' << name << ' ' << id << " attacked " << enemy->part->color << ' ' << enemy->name << ' ' << enemy->id << " in city "
		<< cityNo << " with " << blood << " elements and force " << force << endl;
	if (enemy->blood <= 0) {//���˱�ɱ��
		enemy->blood = 0;
	}
}
void Warrior::fight_back(Warrior* enemy, int t) {
	int tmp_force = force / 2;
	auto i = weapons.begin();
	for (; i != weapons.end(); ++i) {
		if ((*i) != nullptr && (*i)->name == "sword") {//��swordҪ����sword�Ĺ�����
			tmp_force += (*i)->weapon_force;
			(*i)->weapon_force = (*i)->weapon_force * 4 / 5;//sword����
			if ((*i)->weapon_force == 0)//sword��������Ϊ������
				(*i)->lost();
			break;
		}
	}
	enemy->blood -= tmp_force;
	output_time(t);
	cout << ' ' << part->color << ' ' << name << ' ' << id << " fought back against " << enemy->part->color << ' ' << enemy->name << ' ' << enemy->id << " in city "
		<< cityNo << endl;
	if (enemy->blood <= 0) {//���˱�ɱ��
		enemy->blood = 0;
	}
}
void Dragon::yell(int t) {
	output_time(t);
	cout << ' '<<part->color << " dragon " << id << " yelled in city " << cityNo << endl;
}
void Dragon::born_report() {
	cout << ' ' << part->color << ' ' << name << ' ' << id << " born" << endl;
	cout << "Its morale is " << fixed << setprecision(2) << morale << endl;
}
void Iceman::march() {
	cnt_march++;//ǰ������+1
	if (part->color == "red")
		cityNo++;
	else
		cityNo--;
	if (cnt_march % 2 == 0) {//ÿ������
		blood -= 9;
		if (blood <= 0)
			blood = 1;//Ѫ������<=0
		force += 20;
	}
}
void Lion::update_init_blood() {
	init_blood = blood;
}
void Lion::blood_trans(Warrior*enemy) {
	enemy->blood += init_blood;
}
void Lion::born_report() {
	cout << ' ' << part->color << ' ' << name << ' ' << id << " born" << endl;
	cout << "Its loyalty is " << loyalty << endl;
}
void Wolf::get_enemy_weapon(Warrior* enemy) {
	auto i = enemy->weapons.begin();
	for (; i != enemy->weapons.end(); ++i) {
		if ((*i) != nullptr) {//����������
			auto j = weapons.begin();
			for (; j != weapons.end(); ++j) {//���Լ���û����ͬ����
				if ((*j) != nullptr && (*j)->name == (*i)->name) {
					break;
				}
			}
			if (j == weapons.end()) {//û����ͬ����
				weapons.push_back((*i));
				(*i)->master = this;//�ı���������
			}
		}
	}
	sort_weapon();//�ź�����
}
void Weapon::attack(Warrior*enemy,int t) {
}//ʵ���ò���(sword����Ҫattack����)
void Weapon::lost() {
	auto i = find(master->weapons.begin(), master->weapons.end(), this);
	master->weapons.erase(i);//����������ɾȥ������
}
void Arrow::attack(Warrior* enemy,int t) {
	enemy->blood -= weapon_force;
	output_time(t);
	cout << ' ' << master->part->color << ' ' << master->name << ' ' << master->id << " shot";
	if (enemy->blood <= 0) {//�ż�ɱ���Է�
		enemy->blood = 0;
		cout << " and killed " << master->part->enemy_Headquarter->color << ' ' << enemy->name << ' ' << enemy->id;
	}
	cout << endl;
	use_cnt++;//ʹ�ô�������+1
	if (use_cnt==3)//���궪��
		lost();
}
void Bomb::attack(Warrior* enemy,int t) {
	enemy->blood = 0;
	master->blood = 0;
	lost();//һ���ԣ������û����
	output_time(t);
	cout << ' '<<master->part->color<<' ' << master->name << ' ' << master->id << " used a bomb and killed " <<enemy->part->color<<' ' << enemy->name << ' ' << enemy->id << endl;
}

int main()
{
	int t;
	cin >> t;
	for (int ii = 1; ii <= t; ii++) {
		cout << "Case " << ii << ':' << endl;
		int headquarter_m, city_n, time_t;
		cin >> headquarter_m >> city_n >> Arrow::arrow_r >> Lion::lion_k >> time_t;
		cin >> Dragon::mem_blood >> Ninja::mem_blood >> Iceman::mem_blood >> Lion::mem_blood >> Wolf::mem_blood;
		cin >> Dragon::mem_force >> Ninja::mem_force >> Iceman::mem_force >> Lion::mem_force >> Wolf::mem_force;
		//��ʼ������
		Headquarter red(headquarter_m, "red", 0);
		Headquarter blue(headquarter_m, "blue", city_n + 1);
		World myWorld(&red, &blue);
		City _city[25];
		for (int i = 0; i <= city_n + 1; i++) { myWorld.myCity.push_back(&_city[i]); }
		red.enemy_Headquarter = &blue;
		blue.enemy_Headquarter = &red;
		red.position = *(myWorld.myCity.begin());
		blue.position = *(--myWorld.myCity.end());
		//��Ϸ��ʼ
		myWorld.run(time_t);
	}
	//��Ϸ������delete����new������ָ��
	auto i1 = new_weapon_to_delete.begin();
	auto i2 = new_warrior_to_delete.begin();
	for (; i1 != new_weapon_to_delete.end(); ++i1)
		delete(*i1);
	for (; i2 != new_warrior_to_delete.end(); ++i2)
		delete(*i2);
	return 0;
}
