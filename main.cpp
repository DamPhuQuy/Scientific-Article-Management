#include "src/components/appnav.h"
#include "src/repos/repomanager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ArticleRepo a_repo;
    AuthorRepo au_repo;
    RepositoryManager repo(a_repo, au_repo);
    repo.load();

    AppNav nav(repo);
    nav.show();

    return a.exec();
}
