/*

revision 123 <-- good
revision 124
...
revision ??? <-- introduced the bug
...
revision 544
revision 545 <-- bad

*/

int findBadRev(unsigned int good, unsigned int bad) {
    while (good < bad - 1) {
        unsigned int mid = good + (bad - good)/2;
        if (isBad(mid)) {
            bad = mid;
        } else {
            good = mid;
        }
    }
    return bad;
}
