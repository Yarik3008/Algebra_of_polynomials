#pragma once
#include <iostream>
#include <stack>
#include "../postflib/MyPostf.h"
#include "ArrayTable.h"
#include "ListTable.h"
#include "SortedTable.h"
#include "ChainHashTable.h"
#include "DoubleHashTable.h"
#include "AVLTable.h"
using namespace std;

class PolinomTableController {
private:
	list<pair<string, Table*>> tables;
	Table* active = nullptr;
public:
	~PolinomTableController() {
		for (auto& table : tables) {
			if (table.second)
				delete table.second;
				table.second = nullptr;
		}
		active = nullptr;
	}

	void AddTable(string name, Table* table) { 
		tables.push_back(make_pair(name, table));
		if (active == nullptr)
			active = table;
	}
	void ChangeActiveTable(string name) {
		for (auto& table : tables) {
			if (table.first == name) {
				active = table.second;
				break;
			}
		}
	}
	ValueType* Find(const KeyType key) { return active->Find(key); }

	void Insert(const KeyType key, const ValueType& value) {
		for (auto& table : tables) {
			table.second->Insert(key, value);
		}
	}

	void Insert(const KeyType key, const string& value) {
		ValueType Pvalue;
		stack<ValueType> st;

		string postf = MyPostf(value).GetPostfix();
		stringstream stream(postf);
		string word;

		while (std::getline(stream, word, ' ')) {
			if (word == "*" || word == "-" || word == "+") {
				TPolinom l = st.top();
				st.pop();
				TPolinom r = st.top();
				st.pop();

				if (word == "*") st.push(l * r);
				if (word == "+") st.push(l + r);
				if (word == "-") st.push(l - r);
			}
			else {
				try {
					double tmp = stod(word);
					st.push(TPolinom(to_string(tmp)));
				}
				catch (exception) {
					ValueType* tmp = Find(word);
					
					if (!tmp)
						return;

					st.push(*tmp);
				}
			}
		}

		Insert(key, st.top());
	}

	void Delete (const KeyType key) {
		for (auto& table : tables) {
			table.second->Delete(key);
		}
	}

	KeyType GetKey(void) const {
		return active->GetKey();
	}

	const ValueType* GetValuePtr(void) const {
		return active->GetValuePtr();
	}

	ostream& PrintAllTables(ostream& os) {
		for (auto& table : tables) {
			os << "Table \"" << table.first << "\" is printing" << endl;
			os << *table.second << endl;
		}
		return os;
	}
	friend ostream& operator<<(ostream& os, const PolinomTableController& cont);
};


ostream& operator<<(ostream& os, const PolinomTableController& cont) {
	return os << "Active table is printing" << endl << *cont.active;
}