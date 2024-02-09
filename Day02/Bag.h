
class Bag
{
private:
    int redAmount;
    int greenAmount;
    int blueAmount;
public:
    Bag(int redAmount = 0, int greenAmount = 0, int blueAmount = 0) 
        : redAmount(redAmount), greenAmount(greenAmount), blueAmount(blueAmount) {};
    bool CanPick(int howManyRed = 0, int howManyGreen = 0, int howManyBlue = 0);
};
