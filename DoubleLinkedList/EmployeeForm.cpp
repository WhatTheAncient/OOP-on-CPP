#include "EmployeeForm.h"


date get_date(string birthday)
{
	unsigned int fields[3] = { 0, 0, 0 };
	int i = 0;

	string delimiter = ".";
	size_t pos = 0;
	string token;

	while ((pos = birthday.find(delimiter)) != string::npos)
	{
		token = birthday.substr(0, pos);
		fields[i] = stoi(token);
		birthday.erase(0, pos + delimiter.length());
		i++;
	}
	fields[2] = stoi(birthday);

	date local_date{ fields[0], fields[1], fields[2] };

	return local_date;
};

bool validate_birthday(date birthday)
{
	return (birthday.day <= 31 && birthday.month <= 12 && birthday.year <= 2003 && birthday.year >= 1920);
}

bool validate_pass(string pass)
{
	return (pass == "true" || pass == "1" || pass == "True" || pass == "False" || pass == "false" || pass == "0");
};

bool get_pass(string pass)
{
	if (validate_pass(pass))
		return (pass == "true" || pass == "1" || pass == "True");
	else
		throw invalid_argument("Received wrong pass!");
};

istream& operator >> (istream& stream, EmployeeForm& obj)
{
	stream.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Surname: " << endl;
	getline(stream, obj.name);

	cout << "Birthday: " << endl;
	string birthday;
	getline(stream, birthday);
	if (validate_birthday(get_date(birthday)))
		obj.birthday = get_date(birthday);
	else
		throw invalid_argument("Received invalid date!");

	cout << "Education: " << endl;
	getline(stream, obj.education);

	cout << "Address: " << endl;
	getline(stream, obj.address);

	string salary;
	cout << "Salary: " << endl;
	getline(stream, salary);
	obj.salary = stoi(salary);

	string pass;
	cout << "Pass: " << endl;
	getline(stream, pass);
	obj.pass = get_pass(pass);

	return stream;
}