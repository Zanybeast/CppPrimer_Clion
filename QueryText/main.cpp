

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>

#include "Query.h"
#include "TextQuery.h"
#include "QueryResult.h"
#include "AndQuery.h"
#include "OrQuery.h"
#include "Query_base.h"
#include "NotQuery.h"

using namespace std;

const string aTextForCpp = "./aTextForCpp.txt";

int main() {

    ifstream input(aTextForCpp);

    if (input) {
        TextQuery textQuery(input);

        Query query = Query("We");

        cout << query.eval(textQuery) << endl;
    } else {
        cout << "Failed to open files";
    }

    input.close();

    return 0;
}
