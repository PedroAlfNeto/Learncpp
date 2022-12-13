/*
 Quizz 1:
 You are running a website, and you are trying to keep track of how much money
    you make per day from advertising.
 Declare an advertising struct that keeps track of how many ads you’ve shown to readers,
    what percentage of ads were clicked on by users, and how much you earned on average
    from each ad that was clicked. Read in values for each of these fields from the user.
 Pass the advertising struct to a function that prints each of the values, and then calculates how
    much you made for that day (multiply all 3 fields together).
*/

//#include "main.hpp"
#include <iostream>
#include <string_view>
#include <cassert>

// advertising struct
struct AdvertMetrics
{
    int shownAds{};        // how many ads you’ve shown to readers
    double clickedAds_perc{}; // percentage of ads clicked on by users
    double revAds{};          // earned on average earnings from each ad clicked.
};

void printUserAds(const AdvertMetrics& adsmetrics)
{

    std::cout << "The user was shown " << adsmetrics.shownAds << " ads, and clicked on " << adsmetrics.clickedAds_perc << " ads, averagin earnings of " << adsmetrics.revAds << " per click.\n";

    double earnings = (adsmetrics.shownAds * adsmetrics.clickedAds_perc * adsmetrics.revAds);
    std::cout << "Today, the user generated " << earnings << " moneys in earnings\n";
}

int main()
{
    AdvertMetrics user{};

    std::cout << "How many ads where show to users: ";
    std::cin >> user.shownAds;

    std::cout << "What percentage of ads were clicked on by the user: ";
    std::cin >> user.clickedAds_perc;

    std::cout << "What where the average earnings from each ad clicked: ";
    std::cin >> user.revAds;

    printUserAds(user);

    return 0;
}