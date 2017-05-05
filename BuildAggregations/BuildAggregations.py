def get_subsets(all_cols):
    res = [[]]
    for col in all_cols:
        size = len(res)
        for i in range(size):
            res.append(res[i] + [col])
    return res

def get_sql(all_cols, subsets):
    BASE_SQL = "SELECT {cols}, COUNT(DISTINCT userid) FROM the_table {group_by}"
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
    subsets = get_subsets(all_cols)
    print subsets
    print
    print get_sql(all_cols, subsets)

main()
