#include "duckdb.hpp"

using namespace duckdb;

int main() {
	DuckDB db(nullptr);

	Connection con(db);

	// con.Query("CREATE TABLE spotify AS FROM read_csv_auto('dataset.csv')");
	// auto result = con.Query("SELECT * FROM spotify ORDER BY duration_ms DESC");

	con.Query("CREATE TABLE spotify AS FROM read_csv_auto('dataset.csv')");
	con.Query("CREATE INDEX duration_index ON spotify (duration_ms)");
	auto result = con.Query("SELECT COUNT(*) FROM spotify WHERE duration_ms > 149610");
}
