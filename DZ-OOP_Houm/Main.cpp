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
	static unsigned int _CountHuman;

public:
	
	Human(std::string name, std::string second_name, int age) {
		_Name = name;
		_Second_Name = second_name;
		_Age = age;
		void Add_count_human();
	}
	~Human() {
		//delete[];
		void Delete_count_human();
	}
	
	void ShowDataHuman() {
		std::cout <<_Name<< " " << _Second_Name << " Возраст =" << _Age << " лет" << std::endl;
	}
	std::string GetName() { return _Name; }
	std::string GetSecond_Name() { return _Second_Name; }
	int GetAge() { return _Age; }
	static void Add_count_human() {
		_CountHuman++;
	}
	static void Delete_count_human() {
		_CountHuman--;
	}
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
	int GetNumberRoom() { return _Number; }
	void AddHuman(Human& human) {
		_Humans.push_back(human);
	}
	std::vector<Human>::iterator H = _Humans.begin();
	void ShowAllHumans() {
		for (auto H : _Humans)
			H.ShowDataHuman();
	}
	void DelAllHuman() {
		for (auto H : _Humans)
			H.~Human();
	}
	void DelHuman(std::string str) {
		for (auto H : _Humans) {
			if (H.GetName() == str)
				H.~Human();
			if (H.GetSecond_Name() == str)
				H.~Human();
		}
	}
	void DelHuman(int num) {
		for (auto H : _Humans) {
			if (H.GetAge() == num)
				H.~Human();
		}
	}
};

class Houm
{
private:
	std::vector<Room> _Rooms;
public:
	Houm() {};
	void AddRoom(Room &room) {
		_Rooms.push_back(room);
	}
	std::vector<Room>::iterator R = _Rooms.begin();
	void DeleteRoom(int num) {
		for (auto R : _Rooms) {
			if (R.GetNumberRoom() == num)
				R;

		}

	}
};

int main() {
	setlocale(LC_ALL, "Russian");

	Houm Lenina_23;
	Human* FS = new Human("Светлана", "Степановна", 35);
	Human *MI=new Human("Виктор", "Иванов", 47);
	Human* AP = new Human("Афанасий", "Петрович", 77);
	Human* OI = new Human("Ольга", "Иванова", 23);

	Room* Room_1 = new Room(1);
	Room* Room_2 = new Room(2);
	Room* Room_3 = new Room(3);

	Lenina_23.AddRoom(*Room_1);
	Lenina_23.AddRoom(*Room_2);
	Lenina_23.AddRoom(*Room_3);

	Room_1->AddHuman(*FS);
	Room_1->AddHuman(*MI);
	Room_2->AddHuman(*AP);
	Room_3->AddHuman(*OI);


	Room_1->ShowAllHumans();


	Human::ShowCountHuman();



	return 0;
}