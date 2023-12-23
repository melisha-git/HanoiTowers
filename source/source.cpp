#include <iostream>
#include <vector>

void printVC(const std::vector<int>& vc, const std::string& s = "Single array") {
    std::cout << s << std::endl;
    if (vc.empty())
        std::cout << "___";
    for (auto n : vc) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

class HanoiTower {
private:
    std::vector<int> t1_;
    std::vector<int> t2_;
    std::vector<int> t3_;
    int sz_;
public:
    explicit HanoiTower(int n) : t1_(n, 0), sz_(n) {
        for (int i = 1; i <= n; ++i) {
            t1_[i - 1] = n - i + 1;
        }
    }

    void onStart() {
        if (!getMoveTowerStr(sz_, "1->3"))
            throw std::logic_error("No miving");

    }

private:

    bool moveTower(const std::string moveStr) {
        if (moveStr == "1->2") {
            return moveTowerHelper(t1_, t2_);
        }
        else if (moveStr == "1->3") {
            return moveTowerHelper(t1_, t3_);
        }
        else if (moveStr == "2->1") {
            return moveTowerHelper(t2_, t1_);
        }
        else if (moveStr == "2->3") {
            return moveTowerHelper(t2_, t3_);
        }
        else if (moveStr == "3->1") {
            return moveTowerHelper(t3_, t1_);
        }
        else if (moveStr == "3->2") {
            return moveTowerHelper(t3_, t2_);
        }
        return false;
    }

    bool moveTowerHelper(std::vector<int>& t1, std::vector<int>& t2) {
        if (t1.empty())
            return false;
        auto num = t1.back();
        if (t2.empty() || num < t2.back()) {
            t1.pop_back();
            t2.push_back(num);

            std::cout << "\n\nMove...\n\n";
            printVC(t1_, "ONE");
            printVC(t2_, "TWO");
            printVC(t3_, "THREE");

            return true;
        }
        return false;
    }

    bool getMoveTowerStr(int n, std::string eMove) {
        if (n == 1)
            return moveTower(eMove);
        if (eMove == "1->2") {
            if (!getMoveTowerStr(n - 1, "1->3") || !moveTower(eMove) || !getMoveTowerStr(n - 1, "3->2"))
                return false;
            return true;
        }
        else if (eMove == "1->3") {
            if (!getMoveTowerStr(n - 1, "1->2") || !moveTower(eMove) || !getMoveTowerStr(n - 1, "2->3"))
                return false;
            return true;
        }
        else if (eMove == "2->1") {
            if (!getMoveTowerStr(n - 1, "2->3") || !moveTower(eMove) || !getMoveTowerStr(n - 1, "3->1"))
                return false;
            return true;
        }
        else if (eMove == "2->3") {
            if (!getMoveTowerStr(n - 1, "2->1") || !moveTower(eMove) || !getMoveTowerStr(n - 1, "1->3"))
                return false;
            return true;
        }
        else if (eMove == "3->1") {
            if (!getMoveTowerStr(n - 1, "3->2") || !moveTower(eMove) || !getMoveTowerStr(n - 1, "2->1"))
                return false;
            return true;
        }
        else if (eMove == "3->2") {
            if (!getMoveTowerStr(n - 1, "3->1") || !moveTower(eMove) || !getMoveTowerStr(n - 1, "1->2"))
                return false;
            return true;
        }
        return false;
    }

};

int main() {
    srand(time(NULL));
    unsigned int start_time = clock();
    HanoiTower t(6);
    t.onStart();
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;

    return 0;
}