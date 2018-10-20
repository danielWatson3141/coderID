import sys

# fpIn = open("ex.in", "r")
# fpOut = open("ex.out", "w")
fpIn = open("small.in", "r")
fpOut = open("small.out", "w")
# fpIn = open("large.in", "r")
# fpOut = open("large.out", "w")


def raw_input():
    return fpIn.readline().strip()


class Print(object):
    def __init__(self, f):
        self.f = f

    def write(self, text):
        fpOut.write(text)
        self.f.write(text)


class Node:
    def __init__(self, id, links, parent=None):
        self.id = id
        ls = []
        l = get_links_with(links, id)
        for i in l:
            if parent:
                if parent.id in i:
                    continue
            if i[0] == id:
               ls.append(i[1])
            else:
                ls.append(i[0])

        # print "id", id, "ls:", ls

        self.parent = parent
        self.children = []
        for i in ls:
            self.children.append(Node(i, links, self))


    def hasChildren(self):
        return len(self.children) > 0

    def numberOfSiblings(self):
        if self.parent:
            return len(self.parent.children)
        else:
            return 0

    def isBal(self):
        if not (len(self.children) == 0 or len(self.children) == 2):
            return False
        for child in self.children:
            if not child.isBal():
                return False
        return True

    def removeChild(self, id):
        for child in self.children:
            if child.id == id:
                self.children.remove(child)
            else:
                child.removeChild(id)

    def prints(self):
        print self.id

        for child in self.children:
            child.prints()

    def getNodeFor(self, id):
        if id == self.id:
            return self
        for child in self.children:
            a = child.getNodeFor(id)
            if a:
                return a
        return None

    def removeLowest(self):
        for child in self.children:
            if child.hasChildren():
                return child.removeLowest()

        if self.children:
            return self.children.pop(0).id
        else:
            print "sdafsdfppdsfpdpsfp"

    def getS(self):
        s = []
        for c in self.children:
            s.append(c.id)
            s.append(self.id)
            s += c.getS()
        return s

    # def removeOne(self):
    #     for child in self.children:
    #         if child.hasChildren():
    #             if child.removeOne():
    #                 return True
    #
    #     return True

def get_links_with(links, s):
    l = []
    for link in links:
        if s in link:
            l.append(link)
    return l

def do_test():
    line = raw_input()

    N = int(line)

    links = []
    s = []
    for i in range(N-1):
        line = raw_input()
        links.append([x for x in line.split()])
        s.append(line.split()[0])
        s.append(line.split()[1])

    if N == 2:
        return "1"

    roots = []
    leafs = []
    mids = []
    others = []
    for x in set(s):
        if s.count(x) == 1:
            leafs.append(x)
        elif s.count(x) == 2:
            roots.append(x)
        elif s.count(x) == 3:
            mids.append(x)
        else:
            others.append(x)
            pass
            # print "BADBADBAD", s.count(x)

    m = 999999
    old_s = s

    for root in roots + leafs+mids:
        r = Node(root, links)
        while not r.isBal():
            s = r.getS()
            noRemove = True

            mids = []
            for x in set(s):
                if s.count(x) == 2:
                    mids.append(x)
            for mid in mids:
                if mid != root and r.getNodeFor(mid):
                    # print "Removed m", r.getNodeFor(mid).children[0].id
                    r.removeChild(r.getNodeFor(mid).children[0].id)

            leafs = []
            s = r.getS()
            for x in set(s):
                if s.count(x) == 1:
                    leafs.append(x)

            # print "Leafs", leafs

            for leaf in leafs:
                if r.getNodeFor(leaf).numberOfSiblings() != 2:
                    # print "Removed l", leaf
                    noRemove = False
                    r.removeChild(leaf)
            # for mid in roots:
            #     if mid != root and r.getNodeFor(mid) and r.getNodeFor(mid).numberOfSiblings() != 2:
            #         print "Removed m", mid
            #         noRemove = False
            #         r.removeChild(mid)

            if noRemove and not r.isBal():
                t = ""
                for x in set(s):
                    if s.count(x) == 1:
                        t = x
                        break
                # print "Removed t", t
                r.removeChild(t)
            if len(r.children) == 1:
                r.children.pop(0)



        s = r.getS()
        if (len(old_s)-len(s))/2 < m:
            m = (len(old_s)-len(s))/2

        # r.prints()
        # while not r.isBal():
        #     pass
            # r.removeOne()
            # count += 1
    return str(m)


    # print links
    # print leafs
    # print roots
    # print mids

    return ""


def main():
    line = raw_input()
    num_tests = int(line)
    for i in range(num_tests):
        # if i == 53:
        #     print "dsf"
        print "Case #" + str(i+1) + ": " + do_test()
        # return

if __name__ == '__main__':
    if not isinstance(sys.stdout, Print):
        sys.stdout = Print(sys.stdout)
    main()

