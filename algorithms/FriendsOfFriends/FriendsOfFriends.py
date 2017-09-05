from friend_lib import get_friends

def get_common_friends(id1, id2):
    id_list1 = get_friends(id1)
    id_list2 = get_friends(id2)
    return set(id_list1).intersection(id_list2)

def pymk(id):
    f_ids = get_friends(id)
    ff_ids = set()
    for f_id in f_ids:
        ff_ids = ff_ids.union(get_friends(f_id))

    common_friends_count = {
        ffid: get_common_friends(id, ff_id)
        for ff_id in ff_ids
        if ff_id != id and ff_id not in f_ids
    }

    return sorted(common_friends_count.items(), key=lambda x: x[1]))
