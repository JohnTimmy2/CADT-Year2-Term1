#ifndef LIBRARYSYSTEM_HPP
#define LIBRARYSYSTEM_HPP

#include "Member.hpp"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class LibrarySystem {
private:
    vector<Member*> members;

public:
    LibrarySystem() {} // ✅ add this constructor

    ~LibrarySystem() {
        for (Member* member : members) {
            delete member;
        }
    }

    void addMember(string name) {
        members.push_back(new Member(name));
    }

    Member* findMember(string name) const {
        for (Member* member : members) {
            if (member->getName() == name)
                return member;
        }
        return nullptr;
    }

    void displayMemberBooks(string name) const {
        Member* member = findMember(name);
        if (member) {
            cout << member->getName() << ":" << endl;
            member->displayBorrowInfo();
        } else {
            cout << "Member not found" << endl;
        }
    }
};

#endif
