#include "TH1D.h"
#include "TProfile.h"
#include "TGraph.h"
#include "TAttMarker.h"
#include "TFile.h"
#include "TCanvas.h"
#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>


void plotCentTiming(){
  //load list of modules that were run
  TFile * f = TFile::Open("timingFiles/timingHistograms.root","recreate");
  std::string buffer;
  std::vector< std::string > listOfModules;
  std::ifstream inModuleFile("timingFiles/listOfModulesRun.txt");
  int length = 0;
  std::string str1;
  if(!inModuleFile.is_open())
  {
    std::cout << "Error opening jet file. Exiting." <<std::endl;
  }
  else
  {
    while(true)
    {
      inModuleFile >> str1;
      listOfModules.push_back(str1);
      //std::cout << number.at(length) << " " << nPix.at(length) << " " << time.at(length) << std::endl;  
      if(inModuleFile.eof()) break;
      length++;
    }
  }

  //load user defined groups of modules to add together
  std::vector< std::vector< std::string > > listOfUserDefModules;
  std::vector< std::string > tempVec;
  std::ifstream inUserDefFile("timingFiles/userDefinedModuleGroups.txt");
  if(!inUserDefFile.is_open())
  {
    std::cout << "Error opening jet file. Exiting." <<std::endl;
  }
  else
  {
    while(true)
    {
      inUserDefFile >> str1;
      if(inUserDefFile.eof()) break;
      std::cout << str1 << std::endl;
      if(str1.compare("-----")!=0) tempVec.push_back(str1);
      if(str1.compare("-----")==0){
        listOfUserDefModules.push_back(tempVec);
        tempVec.clear();
      }
      //std::cout << number.at(length) << " " << nPix.at(length) << " " << time.at(length) << std::endl;  
    }
  }
  //initialize user-defined timing array
  std::vector< std::vector < double > > timingUserDefModules;
  std::vector< double > tempVecDouble;
  std::cout << "Detected " << listOfUserDefModules.size() << " user-defined modules.  They are: " << std::endl;
  for(int i = 0; i<(int)listOfUserDefModules.size(); i++){
    std::cout << listOfUserDefModules.at(i).at(0) << std::endl;
    timingUserDefModules.push_back(tempVecDouble);
  }


  //load timing info
  std::cout << listOfModules.size() << std::endl;
  for(int j = -1; j<(int)listOfModules.size(); j++){
    std::ifstream inFile(Form("timingFiles/TimingInfoCentrality%s%s.txt",(j==-1)?"":"_",(j==-1)?"":listOfModules.at(j).c_str()));
    std::cout << j << std::endl;
    length = 0;
  
    double col1;
    double col2;
    double col3;
  
    std::vector< double > number;
    std::vector< double > nPix;
    std::vector< double > time;
  
    if(!inFile.is_open())
    {
      std::cout << "Error opening jet file. Exiting." <<std::endl;
    }
    else
    {
      while(true)
      {
        inFile >> col1;
        number.push_back(col1);
        inFile >> col2;
        nPix.push_back(col2);
        inFile >> col3;
        time.push_back(col3);
        //std::cout << number.at(length) << " " << nPix.at(length) << " " << time.at(length) << std::endl;  
        if(inFile.eof()) break;
        length++;
      }
    }

    double factor = 0.995; 
    std::string factorfile ="CPUratio.txt";
    std::ifstream CPUtimeFile(factorfile.c_str(),std::ifstream::in);
  
    double realtime=0;
    double cputime=0;
  
    if ( CPUtimeFile ) {
      while ( !CPUtimeFile.eof() ) {
        CPUtimeFile >> realtime >> cputime ;
      }
    }
    if(realtime!=0 && cputime !=0 && cputime/realtime>0 && cputime/realtime<=1){
      factor=cputime/realtime;
    }
  
    for(int i = 0; i<length; i++){
      number[i] = (number[i]-1)/length*100;
      time[i] = factor*time[i];
    }
   
    std::cout << "User-Defined Modules" << std::endl; 
    //check if in user-defined stuff
    if(j>-1){
      for(unsigned int i = 0; i<listOfUserDefModules.size(); i++){//check all user def modules
        for(unsigned int k = 1; k<listOfUserDefModules.at(i).size(); k++){//scan all parts of the user def module
          if(listOfModules.at(j).compare(listOfUserDefModules.at(i).at(k))==0){ //if this module is in a user def module
            if(timingUserDefModules.at(i).size()!=(unsigned int)length){
              for(int m = 0; m<length; m++) timingUserDefModules.at(i).push_back(time[m]);//fill if first entry into vector
            } else {
              for(int m = 0; m<length; m++) timingUserDefModules.at(i).at(m) += time[m];//otherwise add to whats already there
            }
          }
        }
      }
    }
 
    //plotting
    TProfile * h = new TProfile(Form("%s",j>-1?listOfModules.at(j).c_str():"TotalTiming"),";;",25,0,100);
    for(int i = 0; i<length; i++){
      h->Fill(number[i],time[i]);
    }
    TCanvas * c1 = new TCanvas("c1","c1",800,600);
    h->SetLineColor(kBlack);
    h->SetMarkerColor(kBlack);
    h->SetMarkerStyle(8);
    h->GetXaxis()->SetTitle("Centrality (%)"); 
    h->GetYaxis()->SetTitle("CPU time");
    h->Draw("LEX0");
 
    //output
    if(j==-1){ 
      c1->SaveAs("plots/centralityTiming.png");
      c1->SaveAs("plots/centralityTiming.pdf");
      c1->SaveAs("plots/centralityTiming.C"); 
    }else{
      c1->SaveAs(Form("plots/centralityTiming_%s.png",listOfModules.at(j).c_str()));
      c1->SaveAs(Form("plots/centralityTiming_%s.pdf",listOfModules.at(j).c_str()));
      c1->SaveAs(Form("plots/centralityTiming_%s.C",listOfModules.at(j).c_str())); 
    }
    h->Write();
    delete c1;
    delete h;
    //std::cout << length << std::endl;
  }

  //plotting user-defined stuff
  for(unsigned int k = 0; k<listOfUserDefModules.size(); k++){
    TProfile * h = new TProfile(Form("%s",listOfUserDefModules.at(k).at(0).c_str()),";;",25,0,100);
    for(unsigned int i = 0; i<timingUserDefModules.at(k).size(); i++){
      h->Fill(i/((double)length)*100.0,timingUserDefModules.at(k).at(i));
    }
    TCanvas * c1 = new TCanvas("c1","c1",800,600);
    h->SetLineColor(kBlack);
    h->SetMarkerColor(kBlack);
    h->SetMarkerStyle(8);
    h->GetXaxis()->SetTitle("Centrality (%)"); 
    h->GetYaxis()->SetTitle("CPU time");
    h->Draw("LEX0");
   
    //output
    c1->SaveAs(Form("plots/UserDefined/centralityTiming_%s.png",listOfUserDefModules.at(k).at(0).c_str()));
    c1->SaveAs(Form("plots/UserDefined/centralityTiming_%s.pdf",listOfUserDefModules.at(k).at(0).c_str()));
    c1->SaveAs(Form("plots/UserDefined/centralityTiming_%s.C",listOfUserDefModules.at(k).at(0).c_str())); 
    h->Write();
    delete c1;
    delete h;
  }
  f->Close();
}
