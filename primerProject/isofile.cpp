#include "stdafx.h"
#include "isofile.h"

using namespace std;



int rev(int a)
{
	ostringstream os;//�����
	string s1,s2;
	int r = 0;

	os << a;
	s1 = os.str();//int ת�����ַ���
	copy(s1.rbegin(), s1.rend(), insert_iterator<string>(s2, s2.begin()));//��תs1������s2
	r = atoi(s2.c_str());//�ٰ�s2ת����int �����Ƿ�ת�õ�������
	return r;
}
int ShuZiFanZhuan()
{
	return 0;
	int a, b;
	cin >> a >> b;
	cout << rev(rev(a) + rev(b)) << endl;
	return 0;
}
void HaoWeiLai()
{
	return;
	vector<int> vs;
	int num;
	while (cin.get() != '\n' && cin >> num)
	{
		vs.push_back(num);
	}
	set<int> sets;
	map<int, int> maps;
	copy(vs.begin(), vs.end(), insert_iterator<set<int>>(sets, sets.begin()));

	for (set<int>::iterator pr = sets.begin(); pr != sets.end(); pr++)
	{
		maps[*pr] = static_cast<int>(count(vs.begin(), vs.end(), *pr));
	}
	int result, couts = 0;
	for (auto ps = sets.begin(); ps != sets.end(); ps++)
	{
		//cout << *ps << " " << maps[*ps] << endl;
		if (maps[*ps] > couts)
		{
			result = *ps;
			couts = maps[*ps];
		}
	}
	cout << result << endl;
}
bool getmaxstr(const string a, const string b)
{
	return a + b > b + a;
}
void ShuChuan()
{
	return;
	int n, c;
	while (cin >> n)
	{
		vector<string> b;
		string s;
		for (int i = 0; i < n; i++)
		{
			cin >> c;
			ostringstream os;
			os << c;
			s = os.str();
			b.push_back(s);
		}
		sort(b.begin(), b.end(), getmaxstr);
		for (auto p = b.begin(); p != b.end(); p++)
		{
			cout << *p;
		}
		cout << endl;

	}
	return ;
}
void fileliearn()
{
	ShuZiFanZhuan();
	HaoWeiLai();
	ShuChuan();
	reschflush();
	erjinzhiinandout();
	suijiduquwenjian();
}

void reschflush()
{
	return;
	string filename;
	cin >> filename;
	ofstream fout(filename.c_str(), ios_base::out | ios_base::app);

	string sercrt;
	cin >> sercrt;
	fout << sercrt << endl;
	fout.close();
	fout.clear();

	ifstream fin(filename.c_str());
	fout.open("222.txt", ios_base::out | ios_base::app);
	if (!fin.is_open())
		exit(EXIT_FAILURE);
	char ch;
	while (fin.get(ch))
	{
		fout << ch;
	}
	fin.close();
}

void erjinzhiinandout()
{
	return;
	planet p1;
	cout << fixed << right;
	ifstream fin;
	fin.open(File, ios_base::in | ios_base::binary);
	if (fin.is_open())
	{
		while (fin.read((char *) &p1,sizeof p1))
		{
			cout << setw(20) << p1.name
				<< setprecision(0) << setw(12) << p1.population
				<< setprecision(2) << setw(6) << p1.g << endl;
		}
		fin.close();
	}
	ofstream fout(File, ios_base::out | ios_base::app | ios_base::binary);
	if (!fout.is_open())
	{
		cerr << "can not open the " << File << " for output" << endl;
		exit(EXIT_FAILURE);
	}
	cin.get(p1.name, 20);
	while (p1.name[0] != '\0')
	{
		eatline();
		cin >> p1.population;
		cin >> p1.g;
		eatline();
		fout.write((char *)&p1, sizeof p1);
		cin.get(p1.name, 20);
	}
	fout.close();

	fin.clear();
	fin.open(File, ios_base::in | ios_base::binary);
	if (fin.is_open())
	{
		while (fin.read((char *)&p1, sizeof p1))
		{
			cout << setw(20) << p1.name
				<< setprecision(0) << setw(12) << p1.population
				<< setprecision(2) << setw(6) << p1.g << endl;
		}
		fin.close();
	}
	cout << "======================" << endl;
}

void suijiduquwenjian()
{
	planet p1;
	cout << fixed;
	fstream finout;
	finout.open(File, ios_base::in | ios_base::out | ios_base::binary);
	int ct = 0;
	if (finout.is_open())
	{
		finout.seekg(0);
		while (finout.read((char *) & p1,sizeof p1))
		{
			cout << ct++ << setw(LIM) << p1.name << ":"
				<< setprecision(0) << setw(12) << p1.population
				<< setprecision(2) << setw(6) << p1.g << endl;
		}
		if (finout.eof())
			finout.clear();
		else
		{
			cerr << "error reading file :" << File << endl;
			exit(EXIT_FAILURE);
		}
	}
	else 
	{
		cerr << File << " can not be open!" << endl;
		exit(EXIT_FAILURE);
	}

	long rec;
	cin >> rec;
	eatline();
	if (rec < 0 || rec >= ct)
	{
		cerr << "bye bye!" << endl;
		exit(EXIT_FAILURE);
	}
	streampos place = rec * sizeof p1;
	finout.seekg(place);
	if (finout.fail())
	{
		cerr << "seek a age";
		exit(EXIT_FAILURE);
	}

	finout.read((char *)& p1, sizeof p1);
	cout << rec << setw(LIM) << p1.name << ":"
		<< setprecision(0) << setw(12) << p1.population
		<< setprecision(2) << setw(6) << p1.g << endl;
	if (finout.eof())
		finout.clear();


	cin.get(p1.name, LIM);
	eatline();
	cin >> p1.population;
	cin >> p1.g;
	finout.seekp(place);
	finout.write((char *)& p1, sizeof p1) << flush;
	if (finout.fail())
	{
		cerr << "write a age";
		exit(EXIT_FAILURE);
	}



	ct = 0;
	finout.seekg(0);
	while (finout.read((char *)& p1, sizeof p1))
	{
		cout << ct++ << setw(LIM) << p1.name << ":"
			<< setprecision(0) << setw(12) << p1.population
			<< setprecision(2) << setw(6) << p1.g << endl;
	}
	if (finout.eof())
		finout.clear();
	else
	{
		cerr << "error reading file :" << File << endl;
		exit(EXIT_FAILURE);
	}
}