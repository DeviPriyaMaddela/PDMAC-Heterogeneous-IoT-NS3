// throughput_vs_traffic.cc

#include "ns3/core-module.h"
#include "ns3/gnuplot.h"

using namespace ns3;

int main()
{
    std::vector<double> traffic = {600,800,1000,1200,1400,1600,1800};

    std::vector<double> pdmac = {520,700,900,850,770,700,620};
    std::vector<double> b1    = {380,520,620,590,560,530,500};
    std::vector<double> b2    = {410,560,680,650,620,590,560};
    std::vector<double> b3    = {350,480,560,540,500,470,450};
    std::vector<double> b4    = {430,580,700,670,640,600,570};
    std::vector<double> b5    = {360,500,600,570,540,510,480};
    std::vector<double> b6    = {390,540,640,610,580,550,520};

    Gnuplot plot("throughput_vs_traffic.png");
    plot.SetTitle("Throughput vs Traffic Load");
    plot.SetTerminal("png");
    plot.SetLegend("Traffic Load", "Throughput");

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

    std::ofstream file("throughput_vs_traffic.plt");
    plot.GenerateOutput(file);
    file.close();

    return 0;
}
