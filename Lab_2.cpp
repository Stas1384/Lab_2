#include <iostream>
#include <string>
using namespace std;

class State {
public:
	double territory;	// òåðèòîð³ÿ â êì2
	double population;  // ê³ëüê³ñòü íàñåëåííÿ, îñ³á
	string currancy;	// âàëþòà
	//int isVoting, isParliament, LegitPower, ExecPower, Ruler;
	
	State(double ter, double pop, string curr)
	{
		State::territory = ter;
		State::population = pop;
		State::currancy = curr;
	}
//	~State();

};

/*class Republic : virtual public State
{
public:
	int isVoting, isParliament, LegitPower, ExecPower, Ruler;
	Republic::Republic(double ter, double pop, string curr) :State(territory, population, currancy)
	{
		territory = ter;
		population = pop;
		currancy = curr;
		LegitPower = 2;		// çàêîíîäàâ÷à âëàäà íàëåæèòü ïàðëàìåíòó
		ExecPower = 2;		// âèêîíàâ÷à âëàäà íàëåæèòü óðÿäó
		isParliament = 1;	// ïàðëàìåíò º
		isVoting = 1;		// âëàäà îáèðàºòüñÿ
		Ruler = 1;			// êåðóº ïðåçèäåíò
	}

	void getinfo()
	{
		cout << LegitPower << "\t" << ExecPower << "\t" << isParliament << "\t" << isVoting << "\t" << Ruler << endl;
	}
};
*/
class Kingdom :  virtual public State 
{
public:
	int LegitPower, ExecPower, isParliament, isVoting, Ruler;
	// êîíñòðóêòîð êîï³þâàííÿ
	Kingdom(State &src) :State(src.territory, src.population, src.currancy)
	{
		Kingdom::territory = src.territory;// ter;
		Kingdom::population = src.population;
		Kingdom::currancy = src.currancy;
	}

	void setValues()
	{
		this->LegitPower = 1;		// çàêîíîäàâ÷à âëàäà íàëåæèòü ìîíàðõó
		this->ExecPower = 1;		// âèêîíàâ÷à âëàäà íàëåæèòü ìîíàðõó
		this->isParliament = 0;	// ïàðëàìåíòó íåìàº
		this->isVoting = 0;		// êîðîëü íå îáèðàºòüñÿ
		this->Ruler = 0;			// ïðàâèòü êîðîëü
	}

	void getinfo()
	{
		setValues();
		cout << LegitPower << "\t" << ExecPower << "\t" << isParliament << "\t" << isVoting << "\t" << Ruler << endl;
	}
};

/*class Monarchy : public Republic, public Kingdom	// ìîíàðõ³ÿ ìîæå âêëþ÷àòè åëåìåíòè êîðîë³âñòâà òà ðåñïóáë³êè
{
public:
	int LegitPower, ExecPower, isParliament, isVoting, Ruler; 
	Monarchy::Monarchy(double ter, double pop, string curr) :Republic(territory, population, currancy), Kingdom(territory, population, currancy), State(territory, population, currancy)
	{
		territory = ter;
		population = pop;
		currancy = curr;
		LegitPower = Republic::LegitPower;
		ExecPower = Republic::ExecPower;
		isParliament = Republic::isParliament;
		isVoting = Republic::isVoting;
		Ruler = Kingdom::Ruler;
	}
	
	void getinfo()
	{
		cout << LegitPower << "\t" << ExecPower << "\t" << isParliament << "\t" << isVoting << "\t" << Ruler << endl;
	}
};*/



int main(void)
{
	/*Republic Ukraine;
	Ukraine.currancy = "ãðèâíÿ";
	Ukraine.population = 45.6;
	Ukraine.territory = 603.7;
	cout << "Ukraine: ";
	Ukraine.getinfo();
	*/
	Kingdom *UK = new Kingdom(*(new State(420.7,57.6,"pound")));// :State(603, 45, "gryvna");		// Âåëèêîáðèòàí³ÿ

	cout << "UK: ";
	UK->getinfo();
	/*Kingdom UAE;		// Îá'ºäíàí³ Àðàáñüê³ Åì³ðàòè
	cout << "UAE: ";
	UAE.getinfo();
	*/
	return 0;
}
