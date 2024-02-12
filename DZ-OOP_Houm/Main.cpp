#include<iostream>
#include<string>
#include<iterator>
#include<vector>



class Human
{
private:
	std::string _Name = "";
	std::string _Second_Name = "";
	int _Age = 0;
	static int _CountHuman;

public:
	
	Human(std::string name, std::string second_name, int age) {
		_Name = name;
		_Second_Name = second_name;
		_Age = age;
		//Add_count_human();
		
	}
	~Human() {
		// Delete_count_human();
	}
	
	void ShowDataHuman() {
		std::cout <<_Name<< " " << _Second_Name << ", Возраст = " << _Age << " лет" << std::endl;
	}
	std::string GetName() { return _Name; }
	std::string GetSecond_Name() { return _Second_Name; }
	int GetAge() { return _Age; }
	/*void Add_count_human() {
		_CountHuman++;
	}*/
	/*static void Delete_count_human() {
		_CountHuman--;
	}*/
	static void ShowCountHuman() {
		std::cout << _CountHuman << std::endl;
	}

};


class Room
{
private:
	std::vector<Human> _Humans;
	unsigned int _Number;
public:
	Room(int number) {
		_Number = number;
	}
	~Room(){}
	int GetNumberRoom() { return _Number; }
	auto GetHumans()const { return _Humans; }
	void AddHuman(Human* human) {
		_Humans.push_back(*human);
	}
	
	void ShowAllHumans() {
		/*if (_Humans.empty()) {
			std::cout << " No Humans " << std::endl;
			throw - 1;
		}*/
		for (auto i = _Humans.begin(); i != _Humans.end(); i++) {
			i->ShowDataHuman();
		}
	}
	void DelAllHuman() {
		for (auto i = _Humans.end()-1; i >= _Humans.begin(); ) {
			_Humans.erase(i);
			i--;
		}
	}
	void DelHuman(std::string str) {
		for (auto i = _Humans.begin(); i != _Humans.end(); i++) {
			if (i->GetName() == str){
				_Humans.erase(i);
				i = _Humans.begin();
			}
			if (i->GetSecond_Name() == str) {
				_Humans.erase(i);
				i = _Humans.begin();
			}
		}
	}
	void DelHuman(int num) {
		/*for (auto H : _Humans) {
			if (H.GetAge() == num) {
				_Humans.erase(H);
				H--;
			}
		}*/

		for (auto i = _Humans.begin(); i != _Humans.end(); ++i) {
			if (i->GetAge() == num) {
				_Humans.erase(i);
				i= _Humans.begin();
			}
		}
	}
};

class Houm
{
private:
	std::vector<Room> _Rooms;
public:
	Houm() {};
	void AddRoom(Room *room) {
		_Rooms.push_back(*room);
	}
	void Show_Humans_by_Rooms() {
		for (auto i = _Rooms.begin(); i != _Rooms.end(); i++) {
			std::cout << " Room number: " << i->GetNumberRoom() << std::endl;
			i->ShowAllHumans();
			std::cout << '\n';
		}
		
	}
};

int main() {
	setlocale(LC_ALL, "Russian");

	Houm Lenina_23;
	Room* Room_1 = new Room(1);
	Room* Room_2 = new Room(2);
	Room* Room_3 = new Room(3);

	Lenina_23.AddRoom(Room_1);
	Lenina_23.AddRoom(Room_2);
	Lenina_23.AddRoom(Room_3);

	Human* FS = new Human("Светлана", "Степановна", 35);
	Human* MI = new Human("Виктор", "Иванов", 47);
	Human* AP = new Human("Афанасий", "Петрович", 77);
	Human* OI = new Human("Ольга", "Иванова", 23);
	Human* FF = new Human("Евгения", "Степановна", 55);
	Human* MF = new Human("Ольга", "Иванович", 47);
	Human* AF = new Human("Григорий", "Петрович", 37);
	Human* OF = new Human("Виктория", "Сидорович", 13);

	Room_1->AddHuman(FS);
	Room_1->AddHuman(MI);
	Room_1->AddHuman(AP);
	Room_1->AddHuman(OI);
	Room_2->AddHuman(FF);
	Room_2->AddHuman(MF);
	Room_3->AddHuman(AF);
	Room_3->AddHuman(OF);


	Room_1->ShowAllHumans();
	/*std::cout << '\n';
	Room_1->DelHuman(47);
	Room_1->ShowAllHumans();
	std::cout << '\n';
	Room_1->DelHuman("Светлана");
	Room_1->ShowAllHumans();
	std::cout << '\n';
	Room_1->DelHuman("Иванова");
	Room_1->ShowAllHumans();*/
	std::cout << '\n';
	Room_2->ShowAllHumans();
	std::cout << '\n';
	Room_3->ShowAllHumans();

	Lenina_23.Show_Humans_by_Rooms();



	/*Room_1->DelAllHuman();
	std::cout << '\n';
	Room_1->ShowAllHumans();*/




	return 0;
}