/*
 * factory.cpp --
 *
 * Copyright (C) 2016 liyunteng
 * Auther: liyunteng <li_yunteng@163.com>
 * License: GPL
 * Update time:  2016/12/29 22:54:01
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#include <iostream>
#include <memory>
#include <tr1/memory>

using std::cout;
using std::endl;
class IHuman
{
public:
    IHuman() {}
    virtual ~IHuman() {}

    virtual void Laugh() = 0;
    virtual void Cry()   = 0;
    virtual void Talk()  = 0;
};

class WhiteHuman : public IHuman
{
public:
    WhiteHuman() {}
    virtual ~WhiteHuman() {}

    void Laugh()
    {
        cout << "white human laugh" << endl;
    }
    void Cry()
    {
        cout << "white human cry" << endl;
    }
    void Talk()
    {
        cout << "whit human talk" << endl;
    }
};

class YelloHuman : public IHuman
{
public:
    YelloHuman() {}
    virtual ~YelloHuman()
    {
        cout << "yello human delete" << endl;
    }
    void Laugh()
    {
        cout << "yello human laugh" << endl;
    }
    void Cry()
    {
        cout << "yello human cry" << endl;
    }
    void Talk()
    {
        cout << "yello human talk" << endl;
    }
};

class BlackHuman : public IHuman
{
public:
    BlackHuman() {}
    virtual ~BlackHuman() {}
    void Laugh()
    {
        cout << "black human laugh" << endl;
    }
    void Cry()
    {
        cout << "black human cry" << endl;
    }
    void Talk()
    {
        cout << "black human talk" << endl;
    }
};

class IHumanFactory
{
public:
    IHumanFactory() {}
    virtual ~IHumanFactory() {}

    virtual IHuman *CreateHuman() = 0;
};

class WhiteHumanFactory : public IHumanFactory
{
public:
    WhiteHumanFactory() {}
    virtual ~WhiteHumanFactory() {}
    IHuman *CreateHuman()
    {
        return new WhiteHuman();
    }
};

class YellowHumanFactory : public IHumanFactory
{
public:
    YellowHumanFactory() {}
    virtual ~YellowHumanFactory()
    {
        cout << "yello human factory delete" << endl;
    }

    IHuman *CreateHuman()
    {
        return new YelloHuman();
    }
};

class BlackHumanFactory : public IHumanFactory
{
public:
    BlackHumanFactory() {}
    virtual ~BlackHumanFactory() {}
    IHuman *CreateHuman()
    {
        return new BlackHuman();
    }
};

void
test()
{
    IHumanFactory *pHumanFactory = new YellowHumanFactory();
    IHuman *       pHuman        = pHumanFactory->CreateHuman();
    pHuman->Cry();
    pHuman->Laugh();
    pHuman->Talk();

    delete pHuman;
    delete pHumanFactory;
}

void
test2()
{
    std::tr1::shared_ptr<IHumanFactory> pHumanFactory(new YellowHumanFactory());
    std::tr1::shared_ptr<IHuman>        pHuman(pHumanFactory->CreateHuman());
    pHuman->Cry();
    pHuman->Laugh();
    pHuman->Talk();
}

void
test3()
{
    std::auto_ptr<IHumanFactory> pHumanFactory(new YellowHumanFactory());
    std::auto_ptr<IHuman>        pHuman(pHumanFactory->CreateHuman());

    pHuman->Cry();
    pHuman->Laugh();
    pHuman->Talk();
}

int
main(void)
{
    test3();
    return 0;
}
