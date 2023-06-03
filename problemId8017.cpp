#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <set>

using namespace std;


string print_vec(const vector<int>& vec) {
    stringstream ss;

    for (int i = 0; i < vec.size(); i++) {
        ss << vec[i] << "_";
    }

    string ret;
    ss >> ret;
    return ret;
}

string save_to_str(int fm, const vector<int>& vec) {
    stringstream ss;

    ss << fm << "__";

    for (int i = 0; i < vec.size(); i++) {
        ss << vec[i] << "_";
    }

    string ret;
    ss >> ret;
    return ret;
}

// fn: pour from or to
void dfs(int fm, const vector<int>& caps, vector<int>* buckets,
         set<string>* tries, set<int>* results) {

    string ret = save_to_str(fm, *buckets);
    if (tries->count(ret) != 0) {
        return;
    }

    //cout << "= try = " << ret << endl;
    tries->insert(ret);


    for (int i = 0; i < buckets->size(); i++) {
        if (i == fm) {
            continue;
        }

        // case 1: pour from fm to i
        int a = buckets->at(fm);
        int b = caps[i] - buckets->at(i);
        if (a > b) {
            a = b;
        }

        (*buckets)[fm] -= a;
        (*buckets)[i] += a;
        if (buckets->at(0) == 0) {
            // found
            string ret = print_vec(*buckets);
            //cout << "ret " << ret << endl;
            results->insert(buckets->at(2));
        }

//        if (buckets->at(fm) > 0) {
            // ellegible
            dfs(fm, caps, buckets, tries, results);         
//        }
        
        // back
        (*buckets)[fm] += a;
        (*buckets)[i] -= a;

        // case 2: pour from i to fm
        a = buckets->at(i);
        b = caps[fm] - buckets->at(fm);
        if (a > b) {
            a = b;
        }

        (*buckets)[i] -= a;
        (*buckets)[fm] += a;
        if (buckets->at(0) == 0) {
            // found
            string ret = print_vec(*buckets);
            //cout << "ret " << ret << endl;
            results->insert(buckets->at(2));
        }

//        if (buckets->at(fm) > 0) {
            // ellegible
            dfs(fm, caps, buckets, tries, results);         
//        }
        
        // back
        (*buckets)[i] += a;
        (*buckets)[fm] -= a;
    }
}

int main() {
    vector<int> caps = {8, 9, 10};
    vector<int> buckets = {0, 0, 10};
    set<string> tries;
    set<int> results;

    for (int i = 0; i < buckets.size(); i++) {
        dfs(i, caps, &buckets, &tries, &results);
    }



    for (set<int>::iterator it = results.begin(); it != results.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
