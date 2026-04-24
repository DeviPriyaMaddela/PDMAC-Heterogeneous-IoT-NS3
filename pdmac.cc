        rxPackets += flow.second.rxPackets;
        totalDelay += flow.second.delaySum.GetSeconds();
        throughput += flow.second.rxBytes * 8.0 / simTime / 1024.0;
    }

    double pdr = 0.0;
    double avgDelay = 0.0;

    if (txPackets > 0)
        pdr = (double)rxPackets / txPackets * 100.0;

    if (rxPackets > 0)
        avgDelay = totalDelay / rxPackets;

    std::cout << "\n===== FINAL RESULTS =====\n";
    std::cout << "Nodes = " << numNodes << std::endl;
    std::cout << "Packets Sent = " << txPackets << std::endl;
    std::cout << "Packets Received = " << rxPackets << std::endl;
    std::cout << "PDR = " << pdr << " %" << std::endl;
    std::cout << "Delay = " << avgDelay << " sec" << std::endl;
    std::cout << "Throughput = " << throughput << " Kbps" << std::endl;

    Simulator::Destroy();
    return 0;
}

