#include "duckdb.hpp"

using namespace duckdb;

int main() {
	DuckDB db(nullptr);

	Connection con(db);

	con.Query("CREATE TABLE spotify AS FROM read_csv_auto('dataset.csv')");
	auto result = con.Query("SELECT * FROM spotify ORDER BY duration_ms DESC");
}
