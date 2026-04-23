// energy_vs_traffic.cc

#include "ns3/core-module.h"
#include "ns3/gnuplot.h"

using namespace ns3;

int main()
{
    std::vector<double> traffic = {600,800,1000,1200,1400,1600,1800};

    std::vector<double> pdmac = {18.0,18.0,18.0,18.1,18.1,18.1,18.2};
    std::vector<double> b1    = {19.0,19.5,20.3,21.3,22.3,23.1,24.0};
    std::vector<double> b2    = {19.3,19.8,20.8,22.0,23.0,24.0,25.0};
    std::vector<double> b3    = {20.2,21.0,21.9,23.0,24.1,25.0,26.0};
    std::vector<double> b4    = {19.2,19.7,20.6,21.8,22.9,24.0,25.0};
    std::vector<double> b5    = {20.7,21.3,22.3,23.5,24.5,25.5,26.5};
    std::vector<double> b6    = {20.8,21.5,22.5,23.6,24.6,25.6,26.8};

    Gnuplot plot("energy_vs_traffic.png");
    plot.SetTitle("Energy vs Traffic Load");
    plot.SetTerminal("png");
    plot.SetLegend("Traffic Load", "Energy (J)");

    Gnuplot2dDataset d1,d2,d3,d4,d5,d6,d7;

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

    std::ofstream file("energy_vs_traffic.plt");
    plot.GenerateOutput(file);
    file.close();

    return 0;
}
