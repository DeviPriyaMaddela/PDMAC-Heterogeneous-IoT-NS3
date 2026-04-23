// throughput_vs_nodes.cc

#include "ns3/core-module.h"
#include "ns3/gnuplot.h"

using namespace ns3;

int main()
{
    std::vector<double> nodes = {10,20,30,40,50,60};

    std::vector<double> pdmac = {740,720,690,620,670,600};
    std::vector<double> b1    = {420,410,395,375,365,345};
    std::vector<double> b2    = {460,445,430,420,415,395};
    std::vector<double> b3    = {410,395,385,365,355,335};
    std::vector<double> b4    = {500,485,465,445,425,405};
    std::vector<double> b5    = {430,422,405,390,380,360};
    std::vector<double> b6    = {440,430,415,400,390,370};

    Gnuplot plot("throughput_vs_nodes.png");
    plot.SetTitle("Throughput vs Nodes");
    plot.SetTerminal("png");
    plot.SetLegend("Nodes", "Throughput");

    Gnuplot2dDataset d1,d2,d3,d4,d5,d6,d7;

    d1.SetTitle("PDMAC"); d1.SetStyle(Gnuplot2dDataset::LINES_POINTS);
    d2.SetTitle("B1");    d2.SetStyle(Gnuplot2dDataset::LINES_POINTS);
    d3.SetTitle("B2");    d3.SetStyle(Gnuplot2dDataset::LINES_POINTS);
    d4.SetTitle("B3");    d4.SetStyle(Gnuplot2dDataset::LINES_POINTS);
    d5.SetTitle("B4");    d5.SetStyle(Gnuplot2dDataset::LINES_POINTS);
    d6.SetTitle("B5");    d6.SetStyle(Gnuplot2dDataset::LINES_POINTS);
    d7.SetTitle("B6");    d7.SetStyle(Gnuplot2dDataset::LINES_POINTS);

    for (int i = 0; i < 6; i++)
    {
        d1.Add(nodes[i], pdmac[i]);
        d2.Add(nodes[i], b1[i]);
        d3.Add(nodes[i], b2[i]);
        d4.Add(nodes[i], b3[i]);
        d5.Add(nodes[i], b4[i]);
        d6.Add(nodes[i], b5[i]);
        d7.Add(nodes[i], b6[i]);
    }

    plot.AddDataset(d1);
    plot.AddDataset(d2);
    plot.AddDataset(d3);
    plot.AddDataset(d4);
    plot.AddDataset(d5);
    plot.AddDataset(d6);
    plot.AddDataset(d7);

    std::ofstream file("throughput_vs_nodes.plt");
    plot.GenerateOutput(file);
    file.close();

    return 0;
}
