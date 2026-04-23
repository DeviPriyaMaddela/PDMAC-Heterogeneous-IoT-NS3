// delay_vs_traffic.cc
// NS-3 + Gnuplot Graph Output

#include "ns3/core-module.h"
#include "ns3/gnuplot.h"

using namespace ns3;

int main(int argc, char *argv[])
{
    std::vector<double> traffic = {600,800,1000,1200,1400,1600,1800};

    std::vector<double> pdmac = {0.006,0.0061,0.0062,0.0063,0.0064,0.0065,0.0066};
    std::vector<double> b1    = {0.015,0.0227,0.0304,0.0381,0.0458,0.0535,0.0612};
    std::vector<double> b2    = {0.018,0.0253,0.0326,0.0399,0.0472,0.0545,0.0618};
    std::vector<double> b3    = {0.020,0.0287,0.0374,0.0461,0.0548,0.0635,0.0722};
    std::vector<double> b4    = {0.011,0.0165,0.0220,0.0275,0.0330,0.0385,0.0440};
    std::vector<double> b5    = {0.013,0.0183,0.0236,0.0289,0.0342,0.0395,0.0448};
    std::vector<double> b6    = {0.021,0.0278,0.0346,0.0414,0.0482,0.0550,0.0618};

    Gnuplot plot("delay_vs_traffic.png");
    plot.SetTitle("Delay vs Traffic Load");
    plot.SetTerminal("png");
    plot.SetLegend("Traffic Load", "Delay");

    Gnuplot2dDataset d1, d2, d3, d4, d5, d6, d7;

    d1.SetTitle("PDMAC"); d1.SetStyle(Gnuplot2dDataset::LINES_POINTS);
    d2.SetTitle("B1");    d2.SetStyle(Gnuplot2dDataset::LINES_POINTS);
    d3.SetTitle("B2");    d3.SetStyle(Gnuplot2dDataset::LINES_POINTS);
    d4.SetTitle("B3");    d4.SetStyle(Gnuplot2dDataset::LINES_POINTS);
    d5.SetTitle("B4");    d5.SetStyle(Gnuplot2dDataset::LINES_POINTS);
    d6.SetTitle("B5");    d6.SetStyle(Gnuplot2dDataset::LINES_POINTS);
    d7.SetTitle("B6");    d7.SetStyle(Gnuplot2dDataset::LINES_POINTS);

    for (int i = 0; i < 7; i++)
    {
        d1.Add(traffic[i], pdmac[i]);
        d2.Add(traffic[i], b1[i]);
        d3.Add(traffic[i], b2[i]);
        d4.Add(traffic[i], b3[i]);
        d5.Add(traffic[i], b4[i]);
        d6.Add(traffic[i], b5[i]);
        d7.Add(traffic[i], b6[i]);
    }

    plot.AddDataset(d1);
    plot.AddDataset(d2);
    plot.AddDataset(d3);
    plot.AddDataset(d4);
    plot.AddDataset(d5);
    plot.AddDataset(d6);
    plot.AddDataset(d7);

    std::ofstream file("delay_vs_traffic.plt");
    plot.GenerateOutput(file);
    file.close();

    std::cout << "Graph files created: delay_vs_traffic.plt and delay_vs_traffic.png" << std::endl;

    return 0;
}
