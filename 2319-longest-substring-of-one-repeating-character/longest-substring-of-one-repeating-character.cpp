class Node {
public:
    int len;
    int maxLength;
    int pf;
    int sf;
    char pc;
    char sc;

    Node() {}

    Node(int len, int maxLength, int pf, int sf, char pc, char sc) {
        this->len = len;
        this->maxLength = maxLength;
        this->pf = pf;
        this->sf = sf;
        this->pc = pc;
        this->sc = sc;
    }
};

class Solution {
public:

    Node segTree[400005];

    Node merge(Node &l, Node &r) {

        Node res;

        res.len = l.len + r.len;
        res.pc = l.pc;
        res.sc = r.sc;

        res.maxLength = max(l.maxLength, r.maxLength);
        res.pf = l.pf;
        res.sf = r.sf;

        if (l.sc == r.pc) {

            res.maxLength = max(res.maxLength,
                                l.sf + r.pf);

            if (l.pf == l.len)
                res.pf = l.len + r.pf;

            if (r.sf == r.len)
                res.sf = l.sf + r.len;
        }

        return res;
    }

    void build(int i, int j, int ind, string &s) {

        if (i == j) {
            segTree[ind] = Node(
                1,      // len
                1,      // maxLength
                1,      // pf
                1,      // sf
                s[i],   // pc
                s[i]    // sc
            );
            return;
        }

        int mid = i + (j - i) / 2;

        build(i, mid, 2 * ind + 1, s);
        build(mid + 1, j, 2 * ind + 2, s);

        segTree[ind] = merge(
            segTree[2 * ind + 1],
            segTree[2 * ind + 2]
        );
    }

    void update(int pos, char ch, int i, int j, int ind) {

        if (i == j) {
            segTree[ind] = Node(
                1, 1, 1, 1, ch, ch
            );
            return;
        }

        int mid = i + (j - i) / 2;

        if (pos <= mid)
            update(pos, ch, i, mid, 2 * ind + 1);
        else
            update(pos, ch, mid + 1, j, 2 * ind + 2);

        segTree[ind] = merge(
            segTree[2 * ind + 1],
            segTree[2 * ind + 2]
        );
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {

        int n = s.size();

        build(0, n - 1, 0, s);

        vector<int> ans;

        for (int i = 0; i < queryCharacters.size(); i++) {

            update(
                queryIndices[i],
                queryCharacters[i],
                0, n - 1, 0
            );

            ans.push_back(segTree[0].maxLength);
        }

        return ans;
    }
};