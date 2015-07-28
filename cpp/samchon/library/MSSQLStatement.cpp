#include <samchon/library/MSSQLStatement.hpp>

#include <samchon/library/SQLi.hpp>
#include <samchon/library/XML.hpp>

using namespace std;
using namespace samchon;
using namespace samchon::library;

MSSQLStatement::MSSQLStatement(SQLi *sqli)
	: SQLStatement(sqli) {}
MSSQLStatement::~MSSQLStatement() {}

auto MSSQLStatement::toXML() const -> shared_ptr<XML>
{
	fetch();
	String &str = getDataAsString(1);

	shared_ptr<XML> xml(new XML(str));
	return xml;
}
