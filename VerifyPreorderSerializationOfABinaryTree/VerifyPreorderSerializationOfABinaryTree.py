class Solution(object):
    def isValidSerialization(self, preorder):
        """
        Remember how many empty slots we have.
        A non-null node occupy one slot but create two new slots.
        A null nodes occupy one slot.
        """

        p = preorder.split(',')

        #initially we have one empty slot to put the root in it
        slot = 1
        for node in p:
            # no empty slot to put the current node
            if slot == 0:
                return False

            # a null node?
            if node == '#':
                # ocuppy slot
                slot -= 1
            else:
                # create new slot
                slot += 1

        #we don't allow empty slots at the end
        return slot==0

class Solution(object):
    def isValidSerialization(self, preorder):
        """
        When you see two consecutive "#" characters on stack, pop both of them
        and replace the top element on the stack with "#".
        """

        stk = []
        preorder = preorder.split(',')
        for s in preorder:
            stk.append(s)
            while len(stk) >= 2 and stk[-1] == "#" and stk[-2] == "#":
                h = stk.pop()
                h = stk.pop()
                if not stk:
                    return False
                h = stk.pop()
                stk.append('#')
        return len(stk) == 1 and stk[0] == '#'
