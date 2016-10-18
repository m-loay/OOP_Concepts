/*
 * main.cpp
 *
 *  Created on: Oct 18, 2016
 *      Author: modys
 */

#include"FlyweightFactory.h"

 int main()
{
  DialogBox *dialogs[2];
  dialogs[0] = new FileSelection(FlyweightFactory::getIcon("go"),
    FlyweightFactory::getIcon("stop"), FlyweightFactory::getIcon("select"));

  dialogs[1] = new CommitTransaction(FlyweightFactory::getIcon("select"),
    FlyweightFactory::getIcon("stop"), FlyweightFactory::getIcon("undo"));

  for (int i = 0; i < 2; i++)
    dialogs[i]->draw();

  FlyweightFactory::reportTheIcons();

  for (int i = 0; i < 2; i++)
    delete dialogs[i];
}

