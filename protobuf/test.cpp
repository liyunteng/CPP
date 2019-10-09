// test.cpp - test

// Author : liyunteng <liyunteng@streamocean.com>
// Date   : 2019/10/09

// Copyright (C) 2019 StreamOcean, Inc.
// All rights reserved.
#include <iostream>
#include <fstream>
#include <string>
#include <google/protobuf/util/time_util.h>
#include "person.pb.h"
using namespace std;
using google::protobuf::util::TimeUtil;

void PromptForAddress(test::Person *person) {
    cout << "Enter person ID number: ";
    int id;
    cin >> id;
    person->set_id(id);
    cin.ignore(256, '\n');

    cout << "Enter name: ";
    getline(cin, *person->mutable_name());

    cout << "Enter email address (blank for none): ";
    string email;
    getline(cin, email);
    if (!email.empty()) {
        person->set_email(email);
    }

    while(true) {
        cout << "Enter a phone number (or leave blank to finish): ";
        string number;
        getline(cin, number);
        if (number.empty()) {
            break;
        }

        test::Person::PhoneNumber *pn = person->add_phones();
        pn->set_number(number);

        cout << "Is this a mobile, home or work phone? ";
        string type;
        getline(cin, type);
        if (type == "mobile") {
            pn->set_type(test::Person::MOBILE);
        } else if (type == "home") {
            pn->set_type(test::Person::HOME);
        } else if (type == "work") {
            pn->set_type(test::Person::WORK);
        } else {
            cout << "Unknown phone type, Using default." << endl;
        }
    }
    *person->mutable_last_updated() = TimeUtil::SecondsToTimestamp(time(NULL));
}

void ListPeople(const test::AddressBook &ab)  {
    for (int i = 0; i < ab.people_size(); i++) {
        const test::Person &person = ab.people(i);

        cout << "Person ID: " << person.id() << endl;
        cout << "  Name: " << person.name() << endl;
        if (person.email() != "") {
            cout << "  E-mail address: " << person.email() << endl;
        }

        for (int j = 0; j < person.phones_size(); j++) {
            const test::Person::PhoneNumber &pn = person.phones(j);
            switch(pn.type()) {
            case test::Person::MOBILE:
                cout << "  Mobile phone #: ";
                break;
            case test::Person::HOME:
                cout << "  Home phone #: ";
                break;
            case test::Person::WORK:
                cout << "  Work phone #: ";
                break;
            default:
                cout << "  Unknown phone #: ";
                break;
            }
            cout << pn.number() << endl;
        }
        if (person.has_last_updated()) {
            cout << "  Updated: " << TimeUtil::ToString(person.last_updated()) << endl;
        }
    }
}

int main(int argc, char *argv[])
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    string filename = "./tmp";

    test::AddressBook ab;

    fstream input(filename, ios::in | ios::binary);
    if (!input) {
        cout << filename << ": File not found. Creating a new file." << endl;
    } else if (!ab.ParseFromIstream(&input)) {
        cerr << "Failed to parse address book." << endl;
        return -1;
    }

    ListPeople(ab);
    PromptForAddress(ab.add_people());

    fstream output(filename, ios::out | ios::trunc | ios::binary);
    if (!ab.SerializeToOstream(&output)) {
        cerr << "Failed to write address book." << endl;
        return -1;
    }

    google::protobuf::ShutdownProtobufLibrary();

    return 0;
}

// Local Variables:
// compile-command: "clang++ -Wall -o test test.cpp person.pb.cc -g -lprotobuf"
// End:
