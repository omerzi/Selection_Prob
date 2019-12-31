#ifndef PERSON__H
#define PERSON__H


class Person {
private:
	int p_ID;
	char *p_name;
public:
	const static int NAME_MAX = 20;
	Person();
	Person(int ID, char *name);
	Person(Person & other);
	~Person();
	const int getID() const;
	void setID(const int id);
	void setName(const char * name);

};
#endif // !PERSON_H