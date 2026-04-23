// energy_vs_nodes.cc

#include "ns3/core-module.h"
#include "ns3/gnuplot.h"

using namespace ns3;

int main()
{
    std::vector<double> nodes = {10,20,30,40,50,60};

    std::vector<double> pdmac = {18.0,18.0,18.1,18.1,18.2,18.2};
    std::vector<double> b1    = {19.0,19.6,20.4,21.3,22.3,23.4};
    std::vector<double> b2    = {19.5,20.0,20.9,21.8,22.9,24.1};
    std::vector<double> b3    = {20.3,20.9,21.7,22.7,23.8,25.0};
    std::vector<double> b4    = {19.2,19.8,20.7,21.8,22.9,24.0};
    std::vector<double> b5    = {20.7,21.2,22.1,23.0,24.1,25.1};
    std::vector<double> b6    = {20.8,21.4,22.3,23.3,24.3,25.4};

    Gnuplot plot("energy_vs_nodes.png");
    plot.SetTitle("Energy vs Nodes");
    plot.SetTerminal("png");
    plot.SetLegend("Nodes", "Energy (J)");

    Gnuplot2dDataset d1,d2,d3,d4,d5,d6,d7;

    d1.SetTitle("PDMAC"); d1.SetStyle(Gnuplot2dDataset::LINES_POINTS);
    d2.SetTitle("B1");    d2.SetStyle(Gnuplot2dDataset::LINES_POINTS);
    d3.SetTitle("B2");    d3.SetStyle(Gnuplot2dDataset::LINES_POINTS);
    d4.SetTitle("B3");    d4.SetStyle(Gnuplot2dDataset::LINES_POINTS);
    d5.SetTitle("B4");    d5.SetStyle(Gnuplot2dDataset::LINES_POINTS);
    d6.SetTitle("B5");    d6.SetStyle(Gnuplot2dDataset::LINES_POINTS);
    d7.SetTitle("B6");    d7.SetStyle(Gnuplot2dDataset::LINES_POINTS);

    for(int i=0;i<6;i++)
    {
        d1.Add(nodes[i],pdmac[i]);
        d2.Add(nodes[i],b1[i]);
        d3.Add(nodes[i],b2[i]);
        d4.Add(nodes[i],b3[i]);
        d5.Add(nodes[i],b4[i]);
        d6.Add(nodes[i],b5[i]);
        d7.Add(nodes[i],b6[i]);
    }

    plot.AddDataset(d1);
    plot.AddDataset(d2);
    plot.AddDataset(d3);
    plot.AddDataset(d4);
    plot.AddDataset(d5);
    plot.AddDataset(d6);
    plot.AddDataset(d7);

    std::ofstream file("energy_vs_nodes.plt");
    plot.GenerateOutput(file);
    file.close();

    return 0;
}
