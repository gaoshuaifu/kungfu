class Solution(object):
    def _parse_file_info(self, file_info):
        """
        Input: string "1.txt(abcd)""
        Return: tuple ("1.txt", "abcd")
        """

        file_items = file_info[:-1].split("(")
        return file_items[0], file_items[1]

    def _parse_path(self, path):
        """
        Input: ["root/a 1.txt(abcd) 2.txt(efgh)"]
        Return: [("root/a/1.txt", "abcd"), ("root/a/2.txt", "efgh")]
        """

        path_items = path.split(" ")
        folder = path_items[0]
        res = []
        for file_info in path_items[1:]:
            file_name, content = self._parse_file_info(file_info)
            res.append(("{}/{}".format(folder, file_name), content))
        return res

    def findDuplicate(self, paths):
        from collections import defaultdict
        d = defaultdict(list)
        for path in paths:
            for file_name, content in self._parse_path(path):
                d[content].append(file_name)
        return [v for k, v in d.items() if len(v) > 1]
