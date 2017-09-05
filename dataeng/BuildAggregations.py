BASE_SQL = """
SELECT
    {cols},
    SUM(time_on_site) / COUNT(DISTINCT userid) AS time_on_site_per_dau
FROM user_level_time_on_site
{group_by}
"""

def get_subsets(all_cols):
    res = [[]]
    for col in all_cols:
        size = len(res)
        for i in range(size):
            res.append(res[i] + [col])
    return res

def get_sql(all_cols):
    subsets = get_subsets(all_cols)
    # Table user_level_time_out_site(user_id, time_on_site)
    queries = []
    for subset in subsets:
        cols = []
        for col in all_cols:
            if col in subset:
                cols.append(col)
            else:
                cols.append("'overall' AS %s" % col)

        if subset:
            group_by = "GROUP BY %s\n" % ", ".join(subset)
        else:
            group_by = "\n"

        queries.append(BASE_SQL.format(cols=", ".join(cols), group_by=group_by))

    return "UNION ALL\n".join(queries)


def main():
    all_cols = ["age", "gender", "interface"]
    print get_sql(all_cols)

main()
