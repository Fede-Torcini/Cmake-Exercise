#include "nlohmann/json.hpp"
#include <iostream>
#include <map>

using namespace std;
using json = nlohmann::json;

/*
 * Given a json object, an index reference and a map pointer
 * adds to the map the json at it's index + key.
 * In case of nested objects it´s indexed with a "." inbetween.
 */
void iterate_json(json myObject, string cur_index, map<string, json>* myMap)
{
	//for each key in my json object
	for (auto& el : myObject.items())
	{
		json value = el.value();

		//if my element is a json object, iterate throught it
		if (value.is_object())
		{
			//recursive call
			iterate_json(value, cur_index + el.key() + ".", myMap);
		}
		else
		{
			string index = cur_index + el.key();
			myMap->insert({index, value});
		}
	}
}


/*
 * Given text with JSON format
 * adds returns all json objects in a map
 * indexing at it´s key value. In case of nesting
 * it´s indexed with a "." inbetween.
 */
map<string, json> dictionary_of_JSON(string data)
{
	map<string, json> myMap;

	//parse json & start recursivity
	json myObject = json::parse(data);
	iterate_json(myObject, "", &myMap);
	return myMap;
}


int main() {
	string data = R"(
		{
			"a": true,
			"b": {
					"b1": "hello",
					"b2": 3.5
				 },
			"c": 3,
			"d": {
					"d1": "nice",
					"d2": {
								"d21": 546
						  }
				  }
		}
	)";
	map<string, json> myMap = dictionary_of_JSON(data);

	while (true)
	{
		string input;
		getline(cin, input);

		cout << myMap.at(input)<< "\n";
	}

}