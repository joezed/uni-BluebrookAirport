#include <stdio.h>
#include "stdafx.h"
#include <iostream>
#include "tinyxml2.h"

using namespace tinyxml2;
using namespace std;

#ifndef XMLCheckResult
#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

int main() {
	XMLDocument xmlDoc;
	XMLNode * pRoot = xmlDoc.NewElement("Root");
	xmlDoc.InsertFirstChild(pRoot);

	XMLElement * pElement = xmlDoc.NewElement("IntValue");
	pElement->SetText(10);
	pRoot->InsertEndChild(pElement);
	pElement = xmlDoc.NewElement("FloatValue");
	pElement->SetText(0.5f);
	pRoot->InsertEndChild(pElement);
	// The other accepted primitive types are unsigned int, double, bool and const char *.

	pElement = xmlDoc.NewElement("Date");
	pElement->SetAttribute("day", 26);
	pElement->SetAttribute("month", "April");
	pElement->SetAttribute("year", 2014);
	pElement->SetAttribute("dateFormat", "26/04/2014");
	pRoot->InsertEndChild(pElement);

	

	pElement = xmlDoc.NewElement("List");
	for (const auto & item : vecList)
	{
		XMLElement * pListElement = xmlDoc.NewElement("Item");
		pListElement->SetText(item);

		pElement->InsertEndChild(pListElement);
	}

	pElement->SetAttribute("itemCount", vecGroup.size());
	pRoot->InsertEndChild(pElement);

	XMLError eResult = xmlDoc.SaveFile("SavedData.xml");
	XMLCheckResult(eResult);
}
