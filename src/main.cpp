#include "repositories/RepositoryManager.h"
#include "services/DataManipulation.h"

using namespace std;

void start() {
    DataManipulation data_m;
    RepositoryManager repo(
        data_m.init<Article*>(),
        data_m.init<Author>(),
        data_m.init<Journal>()
    );
}

int main() {
    start();
    return 0;
}