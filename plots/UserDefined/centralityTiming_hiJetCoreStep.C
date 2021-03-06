void centralityTiming_hiJetCoreStep()
{
//=========Macro generated from canvas: c1/c1
//=========  (Fri May  5 17:03:30 2017) by ROOT version6.08/05
   TCanvas *c1 = new TCanvas("c1", "c1",0,0,800,600);
   c1->Range(-12.5,0.02147533,112.5,0.08779293);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TProfile *hiJetCoreStep = new TProfile("hiJetCoreStep","",25,0,100,"");
   hiJetCoreStep->SetBinEntries(1,26);
   hiJetCoreStep->SetBinEntries(2,26);
   hiJetCoreStep->SetBinEntries(3,26);
   hiJetCoreStep->SetBinEntries(4,26);
   hiJetCoreStep->SetBinEntries(5,26);
   hiJetCoreStep->SetBinEntries(6,26);
   hiJetCoreStep->SetBinEntries(7,25);
   hiJetCoreStep->SetBinEntries(8,26);
   hiJetCoreStep->SetBinEntries(9,26);
   hiJetCoreStep->SetBinEntries(10,26);
   hiJetCoreStep->SetBinEntries(11,26);
   hiJetCoreStep->SetBinEntries(12,26);
   hiJetCoreStep->SetBinEntries(13,25);
   hiJetCoreStep->SetBinEntries(14,26);
   hiJetCoreStep->SetBinEntries(15,26);
   hiJetCoreStep->SetBinEntries(16,26);
   hiJetCoreStep->SetBinEntries(17,26);
   hiJetCoreStep->SetBinEntries(18,26);
   hiJetCoreStep->SetBinEntries(19,25);
   hiJetCoreStep->SetBinEntries(20,26);
   hiJetCoreStep->SetBinEntries(21,26);
   hiJetCoreStep->SetBinEntries(22,26);
   hiJetCoreStep->SetBinEntries(23,26);
   hiJetCoreStep->SetBinEntries(24,26);
   hiJetCoreStep->SetBinEntries(25,25);
   hiJetCoreStep->SetBinContent(1,1.450364);
   hiJetCoreStep->SetBinContent(2,1.322409);
   hiJetCoreStep->SetBinContent(3,1.2718);
   hiJetCoreStep->SetBinContent(4,1.19852);
   hiJetCoreStep->SetBinContent(5,1.126193);
   hiJetCoreStep->SetBinContent(6,1.07887);
   hiJetCoreStep->SetBinContent(7,1.061562);
   hiJetCoreStep->SetBinContent(8,1.034319);
   hiJetCoreStep->SetBinContent(9,1.076035);
   hiJetCoreStep->SetBinContent(10,1.053673);
   hiJetCoreStep->SetBinContent(11,0.9892614);
   hiJetCoreStep->SetBinContent(12,0.9885708);
   hiJetCoreStep->SetBinContent(13,1.45363);
   hiJetCoreStep->SetBinContent(14,0.9393543);
   hiJetCoreStep->SetBinContent(15,0.9188933);
   hiJetCoreStep->SetBinContent(16,0.9013174);
   hiJetCoreStep->SetBinContent(17,0.9212053);
   hiJetCoreStep->SetBinContent(18,0.8851582);
   hiJetCoreStep->SetBinContent(19,0.846723);
   hiJetCoreStep->SetBinContent(20,0.9148503);
   hiJetCoreStep->SetBinContent(21,0.9039092);
   hiJetCoreStep->SetBinContent(22,0.8585509);
   hiJetCoreStep->SetBinContent(23,0.8420173);
   hiJetCoreStep->SetBinContent(24,0.8865717);
   hiJetCoreStep->SetBinContent(25,0.7754221);
   hiJetCoreStep->SetBinError(1,0.287956);
   hiJetCoreStep->SetBinError(2,0.2617038);
   hiJetCoreStep->SetBinError(3,0.252069);
   hiJetCoreStep->SetBinError(4,0.2376766);
   hiJetCoreStep->SetBinError(5,0.2227054);
   hiJetCoreStep->SetBinError(6,0.2135661);
   hiJetCoreStep->SetBinError(7,0.2146027);
   hiJetCoreStep->SetBinError(8,0.203783);
   hiJetCoreStep->SetBinError(9,0.2137198);
   hiJetCoreStep->SetBinError(10,0.2085887);
   hiJetCoreStep->SetBinError(11,0.1949656);
   hiJetCoreStep->SetBinError(12,0.1954115);
   hiJetCoreStep->SetBinError(13,0.5889913);
   hiJetCoreStep->SetBinError(14,0.1858497);
   hiJetCoreStep->SetBinError(15,0.1811094);
   hiJetCoreStep->SetBinError(16,0.1777745);
   hiJetCoreStep->SetBinError(17,0.1824752);
   hiJetCoreStep->SetBinError(18,0.1745416);
   hiJetCoreStep->SetBinError(19,0.1715735);
   hiJetCoreStep->SetBinError(20,0.1818697);
   hiJetCoreStep->SetBinError(21,0.1799);
   hiJetCoreStep->SetBinError(22,0.169805);
   hiJetCoreStep->SetBinError(23,0.1664544);
   hiJetCoreStep->SetBinError(24,0.1757153);
   hiJetCoreStep->SetBinError(25,0.1555949);
   hiJetCoreStep->SetEntries(646);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.695,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *AText = ptstats->AddText("hiJetCoreStep");
   AText->SetTextSize(0.0368);
   AText = ptstats->AddText("Entries = 646    ");
   AText = ptstats->AddText("Mean  =  49.92");
   AText = ptstats->AddText("Mean y = 0.03978");
   AText = ptstats->AddText("Std Dev   =  28.87");
   AText = ptstats->AddText("Std Dev y = 0.02202");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   hiJetCoreStep->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(hiJetCoreStep);
   hiJetCoreStep->SetMarkerStyle(8);
   hiJetCoreStep->GetXaxis()->SetTitle("Centrality (%)");
   hiJetCoreStep->GetXaxis()->SetLabelFont(42);
   hiJetCoreStep->GetXaxis()->SetLabelSize(0.035);
   hiJetCoreStep->GetXaxis()->SetTitleSize(0.035);
   hiJetCoreStep->GetXaxis()->SetTitleFont(42);
   hiJetCoreStep->GetYaxis()->SetTitle("CPU time");
   hiJetCoreStep->GetYaxis()->SetLabelFont(42);
   hiJetCoreStep->GetYaxis()->SetLabelSize(0.035);
   hiJetCoreStep->GetYaxis()->SetTitleSize(0.035);
   hiJetCoreStep->GetYaxis()->SetTitleFont(42);
   hiJetCoreStep->GetZaxis()->SetLabelFont(42);
   hiJetCoreStep->GetZaxis()->SetLabelSize(0.035);
   hiJetCoreStep->GetZaxis()->SetTitleSize(0.035);
   hiJetCoreStep->GetZaxis()->SetTitleFont(42);
   hiJetCoreStep->Draw("LEX0");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
