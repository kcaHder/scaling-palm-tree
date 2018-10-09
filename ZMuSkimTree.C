#define ZMuSkimTree_cxx
#include "ZMuSkimTree.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TH1F.h>
#include <TVector.h>
#include <iostream>
#include <TH2F.h>
#include <TGraph.h>
#include <vector>



void ZMuSkimTree::Loop()
{
//   In a ROOT session, you can do:
//      root> .L ZMuSkimTree.C
//      root> ZMuSkimTree t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();
   //if (maxentries>-1) nentries=maxentries;

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
   }
}


void ZMuSkimTree::Count()
{
  
	if (fChain == 0) return;

	Long64_t nentries = fChain->GetEntriesFast();
	clog << nentries<< "\n";
	//if (maxentries>-1) nentries=maxentries;
	Long64_t nbytes = 0, nb = 0;
	Long64_t phicount = 0, simphicount = 0;
  TH2F* h = new TH2F ("wheel0", "wheel0", 28, -0.5, 12.5,10,0,5);
  TH2F* h2 = new TH2F ("wheel1", "wheel1", 28, -0.5, 12.5,10,0,5);
  TH2F* h3 = new TH2F ("wheel2", "wheel2", 28, -0.5, 12.5,10,0,5);
  TH2F* h4 = new TH2F ("wheel-1", "wheel-1", 28, -0.5, 12.5,10,0,5);
  TH2F* h5 = new TH2F ("wheel-2", "wheel-2", 28, -0.5, 12.5,10,0,5);
  TH2F* Lh = new TH2F ("wheel0", "wheel0", 28, -0.5, 12.5,10,0,5);
  TH2F* Lh2 = new TH2F ("wheel1", "wheel1", 28, -0.5, 12.5,10,0,5);
  TH2F* Lh3 = new TH2F ("wheel2", "wheel2", 28, -0.5, 12.5,10,0,5);
  TH2F* Lh4 = new TH2F ("wheel-1", "wheel-1", 28, -0.5, 12.5,10,0,5);
  TH2F* Lh5 = new TH2F ("wheel-2", "wheel-2", 28, -0.5, 12.5,10,0,5);

  //double* sp = new double [nentries];
  //double* rp = new double [nentries];
  long int j = 0;
	Long64_t diff = 0;
  vector<int> fillingplus[10];
  vector<int> fillingless[10];
  TCanvas* c1 = new TCanvas("c1","c1");
  TCanvas* c2 = new TCanvas("c2","c2");
  //TCanvas* c3 = new TCanvas("c3","c3");
  //TCanvas* c4 = new TCanvas("c4","c4");
  //TCanvas* c5 = new TCanvas("c5","c5");
  c1->Divide(3,2);
  c2->Divide(3,2);
  //TH1F* hwh0 = new TH1F("hwh0","number of hits wheel 0",);
	for (Long64_t jentry=0; jentry<nentries;jentry++) 
	{
		//clog << "first for" << jentry << endl;
    	Long64_t ientry = LoadTree(jentry);
    	if (ientry < 0) break;
    	fChain->SetBranchStatus("*",0); 
    	fChain->SetBranchStatus("ltSimTwinMuxOut_phi",1);
      fChain->SetBranchStatus("ltTwinMuxOut_phi",1);
      fChain->SetBranchStatus("ltTwinMuxOut_wheel",1);
      fChain->SetBranchStatus("ltTwinMuxOut_sector",1);
      fChain->SetBranchStatus("ltTwinMuxOut_station",1);
      fChain->SetBranchStatus("ltSimTwinMuxOut_wheel",1);
      fChain->SetBranchStatus("ltSimTwinMuxOut_sector",1);
      fChain->SetBranchStatus("ltSimTwinMuxOut_station",1);

    	//nb = fChain->GetEntry(jentry);   nbytes += nb;
      /*if (ltSimTwinMuxOut_phi->size()== ltTwinMuxOut_phi->size())
      {
        
        for (unsigned int i = 0; i < ltSimTwinMuxOut_phi->size(); ++i)
        {
          int wh=0;
          int sec=1;
          if(ltTwinMuxOut_wheel->at(i) == wh && ltTwinMuxOut_sector->at(i)==sec && ltSimTwinMuxOut_wheel->at(i) == wh && ltSimTwinMuxOut_sector->at(i)==sec)
          {
          
            
            int sta=ltTwinMuxOut_station->at(i);
            int Swh=ltSimTwinMuxOut_wheel->at(i);
            int Ssec=ltSimTwinMuxOut_sector->at(i);
            int Ssta=ltSimTwinMuxOut_station->at(i);
            clog << i << endl;
            clog << "wh"<<ltTwinMuxOut_wheel->at(i)<<endl;
            clog << "sec"<<ltTwinMuxOut_sector->at(i)<<endl;
            clog << "sta"<<sta<<endl;
            clog << "Swh"<<Swh<<endl;
            clog << "Ssec"<<Ssec<<endl;
            clog << "Ssta"<<Ssta<<endl; 
            sp[j] = ltSimTwinMuxOut_phi->at(i);
            rp[j] = ltTwinMuxOut_phi->at(i);

            j++;
          }


          

        }
      }*/
      //else
      if (ltSimTwinMuxOut_phi->size()!= ltTwinMuxOut_phi->size())
      {
        if (ltSimTwinMuxOut_phi->size() > ltTwinMuxOut_phi->size())
        {
          for (unsigned int i = (ltSimTwinMuxOut_phi->size()-ltTwinMuxOut_phi->size()); i <ltSimTwinMuxOut_phi->size() ; ++i)
          {
            clog << "first case\n";
            //int wh=ltTwinMuxOut_wheel->at(i);
            //int sec=ltTwinMuxOut_sector->at(i);
            //int sta=ltTwinMuxOut_station->at(i);
            int Swh=ltSimTwinMuxOut_wheel->at(i);
            int Ssec=ltSimTwinMuxOut_sector->at(i);
            int Ssta=ltSimTwinMuxOut_station->at(i);
            clog << i << endl;
            //clog << "wh"<<ltTwinMuxOut_wheel->at(i)<<endl;
            //clog << "sec"<<ltTwinMuxOut_sector->at(i)<<endl;
            //clog << "sta"<<sta<<endl;
            //clog << "Swh"<<Swh<<endl;
            //clog << "Ssec"<<Ssec<<endl;
            //clog << "Ssta"<<Ssta<<endl; 
            switch(Swh)
            {
              case 0:
              fillingplus[0].push_back(Ssec);
              fillingplus[1].push_back(Ssta);
              clog << "Scase0\n";
              break;
              case 1:
              fillingplus[2].push_back(Ssec);
              fillingplus[3].push_back(Ssta);
              clog << "Scase1\n";
              break;
              case 2:
              fillingplus[4].push_back(Ssec);
              fillingplus[5].push_back(Ssta);
              clog << "Scase2\n";
              break;
              case -1:
              fillingplus[6].push_back(Ssec);
              fillingplus[7].push_back(Ssta);
              clog << "Scase-1\n";
              break;
              case -2:
              fillingplus[8].push_back(Ssec);
              fillingplus[9].push_back(Ssta);
              clog << "Scase-2\n";
              break;
              default: break;
            }
          }
          //TGraph* g = new TGraph(fillingplus[0].size(),fillingplus[0].data(),fillingplus[1].data());
           //g->Draw();
          
          std::vector<int>::iterator j=fillingplus[1].begin();
          for (std::vector<int>::iterator i = fillingplus[0].begin(); i != fillingplus[0].end(); ++i)
          {
            clog << "*j " <<*j << '\t';
            clog << "fillingh\n";
            h->Fill(*i,*j);
            ++j;
            
           
          }
          std::vector<int>::iterator k=fillingplus[3].begin();
          for (std::vector<int>::iterator kk = fillingplus[2].begin(); kk != fillingplus[2].end(); ++kk)
          {
            clog << "*k " <<*k << '\t';
            clog << "fillingh2\n";
            h2->Fill(*kk,*k);
            ++k;
            
           
          }
          std::vector<int>::iterator l=fillingplus[5].begin();
          for (std::vector<int>::iterator ll = fillingplus[4].begin(); ll != fillingplus[4].end(); ++ll)
          {
            clog << "*l " <<*l << '\t';
            clog << "fillingh3\n";
            h3->Fill(*ll,*l);
            ++l;
            
           
          }
          std::vector<int>::iterator m=fillingplus[7].begin();
          for (std::vector<int>::iterator mm = fillingplus[6].begin(); mm != fillingplus[6].end(); ++mm)
          {
            clog << "*m " <<*m << '\t';
            clog << "fillingh4\n";
            h4->Fill(*mm,*m);
            ++m;
            
           
          }
          std::vector<int>::iterator n=fillingplus[9].begin();
          for (std::vector<int>::iterator nn = fillingplus[8].begin(); nn != fillingplus[8].end(); ++nn)
          {
            clog << "*n " <<*n << '\t';
            clog << "fillingh5\n";
            h5->Fill(*nn,*n);
            ++n;
            
           
          }
          

          //h->FillN(fillingplus[0].size(),const_cast<double*>(fillingplus[0].data()),const_cast<double*>(fillingplus[1].data()),1);
          
        }
        
        
        

        else
        {
          for (unsigned int i = (ltTwinMuxOut_phi->size()-ltSimTwinMuxOut_phi->size()); i <ltTwinMuxOut_phi->size() ; ++i)
          {
            clog<< "second case\n";
            int wh=ltTwinMuxOut_wheel->at(i);
            int sec=ltTwinMuxOut_sector->at(i);
            int sta=ltTwinMuxOut_station->at(i);
            //int Swh=ltSimTwinMuxOut_wheel->at(i);
            //int Ssec=ltSimTwinMuxOut_sector->at(i);
            //int Ssta=ltSimTwinMuxOut_station->at(i);
            //clog << i << endl;
            //clog << "wh"<<wh<<endl;
            //clog << "sec"<<sec<<endl;
            //clog << "sta"<<sta<<endl;
            //clog << "Swh"<<Swh<<endl;
            //clog << "Ssec"<<Ssec<<endl;
            //clog << "Ssta"<<Ssta<<endl; 
            switch(wh)
            {
              case 0:
              fillingless[0].push_back(sec);
              fillingless[1].push_back(sta);
              clog << "case0\n";
              break;
              case 1:
              fillingless[2].push_back(sec);
              fillingless[3].push_back(sta);
              clog << "case1\n";
              break;
              case 2:
              fillingless[4].push_back(sec);
              fillingless[5].push_back(sta);
              clog << "case2\n";
              break;
              case -1:
              fillingless[6].push_back(sec);
              fillingless[7].push_back(sta);
              clog << "case-1\n";
              break;
              case -2:
              fillingless[8].push_back(sec);
              fillingless[9].push_back(sta);
              clog << "case-2\n";
              break;
              default: break;
            }
          }

          std::vector<int>::iterator j=fillingless[1].begin();
          for (std::vector<int>::iterator i = fillingless[0].begin(); i != fillingless[0].end(); ++i)
          {
            clog << "*j " <<*j << '\t';
            clog << "fillingh\n";
            Lh->Fill(*i,*j);
            ++j;
            
           
          }
          std::vector<int>::iterator k=fillingless[3].begin();
          for (std::vector<int>::iterator kk = fillingless[2].begin(); kk != fillingless[2].end(); ++kk)
          {
            clog << "*k " <<*k << '\t';
            clog << "fillingh2\n";
            Lh2->Fill(*kk,*k);
            ++k;
            
           
          }
          std::vector<int>::iterator l=fillingless[5].begin();
          for (std::vector<int>::iterator ll = fillingless[4].begin(); ll != fillingless[4].end(); ++ll)
          {
            clog << "*l " <<*l << '\t';
            clog << "fillingh3\n";
            Lh3->Fill(*ll,*l);
            ++l;
            
           
          }
          std::vector<int>::iterator m=fillingless[7].begin();
          for (std::vector<int>::iterator mm = fillingless[6].begin(); mm != fillingless[6].end(); ++mm)
          {
            clog << "*m " <<*m << '\t';
            clog << "fillingh4\n";
            Lh4->Fill(*mm,*m);
            ++m;
            
           
          }
          std::vector<int>::iterator n=fillingless[9].begin();
          for (std::vector<int>::iterator nn = fillingless[8].begin(); nn != fillingless[8].end(); ++nn)
          {
            clog << "*n " <<*n << '\t';
            clog << "fillingh5\n";
            Lh5->Fill(*nn,*n);
            ++n;
            
           
          }

        }
        fillingplus[0].clear();
        fillingplus[1].clear();
        fillingplus[2].clear();
        fillingplus[3].clear();
        fillingplus[4].clear();
        fillingplus[5].clear();
        fillingplus[6].clear();
        fillingplus[7].clear();
        fillingplus[8].clear();
        fillingplus[9].clear();
        fillingless[0].clear();
        fillingless[1].clear();
        fillingless[2].clear();
        fillingless[3].clear();
        fillingless[4].clear();
        fillingless[5].clear();
        fillingless[6].clear();
        fillingless[7].clear();
        fillingless[8].clear();
        fillingless[9].clear();


      }
    	
    	//clog << "second gt done\n";
    	/*for (std::vector<float>::iterator i = ltSimTwinMuxOut_phi->begin(); i != ltSimTwinMuxOut_phi->end(); ++i)
    	{
    		//cout << "simulati\n" << *i << "/////////////////////////////////////////////////asdasda\n";
    		simphicount += 1;
    		//cout << "simphicount\n" << simphicount << endl;
    	
    	}
    	for (std::vector<float>::iterator j = ltTwinMuxOut_phi->begin(); j != ltTwinMuxOut_phi->end(); ++j)
    	{
    		//cout << "reali\n" << *i << "/////////////////////////////////////////////////asdasda\n";
    		phicount += 1;
    		//cout << "phicount\n" << phicount << endl;
    	
    	}

    	diff += (ltTwinMuxOut_phi->size()-ltSimTwinMuxOut_phi->size())*(ltTwinMuxOut_phi->size()-ltSimTwinMuxOut_phi->size());
      h->Fill(ltTwinMuxOut_phi->size(),ltSimTwinMuxOut_phi->size());
     */
    }	
    
    

    c1->cd(1);
    h->Draw(); 
    c1->cd(2);
    h2->Draw();    
    c1->cd(3);
    h3->Draw();   
    c1->cd(4);
    h4->Draw();
    c1->cd(5);
    h5->Draw();
    c1->Draw();

    c2->cd(1);
    Lh->Draw(); 
    c2->cd(2);
    Lh2->Draw();    
    c2->cd(3);
    Lh3->Draw();   
    c2->cd(4);
    Lh4->Draw();
    c2->cd(5);
    Lh5->Draw();
    c2->Draw();    
}


void ZMuSkimTree::PhiWheelDist()
{
  if (fChain == 0) return;

    Long64_t nentries = fChain->GetEntriesFast();
   //if (maxentries>-1) nentries=maxentries;
    vector<float> phi[10];
    TCanvas* c3 = new TCanvas("c3","c3");
    //TCanvas* c2 = new TCanvas("c2","c2");
    c3->Divide(3,2);

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) 
   {
      clog <<"jentry" << jentry << endl;
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      fChain->SetBranchStatus("*",0); 
      fChain->SetBranchStatus("ltSimTwinMuxOut_phi",1);
      fChain->SetBranchStatus("ltTwinMuxOut_phi",1);
      fChain->SetBranchStatus("ltTwinMuxOut_wheel",1);
      fChain->SetBranchStatus("ltTwinMuxOut_sector",1);
      fChain->SetBranchStatus("ltTwinMuxOut_station",1);
      fChain->SetBranchStatus("ltSimTwinMuxOut_wheel",1);
      fChain->SetBranchStatus("ltSimTwinMuxOut_sector",1);
      fChain->SetBranchStatus("ltSimTwinMuxOut_station",1);

      //nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      
      if (ltSimTwinMuxOut_phi->size()== ltTwinMuxOut_phi->size())
      {
        clog<< "primo if\n";
        for (unsigned int i = 0; i < ltSimTwinMuxOut_phi->size(); ++i)
        {
          clog<<"for\n";
          switch(ltSimTwinMuxOut_wheel->at(i))
          {
            case 0:
            clog<<"caso0\n";
            phi[0].push_back(ltTwinMuxOut_phi->at(i));
            phi[1].push_back(ltSimTwinMuxOut_phi->at(i));
            break;
            case 1:
            clog<<"caso1\n";
            phi[2].push_back(ltTwinMuxOut_phi->at(i));
            phi[3].push_back(ltSimTwinMuxOut_phi->at(i));
            break;
            case 2:
            clog<<"caso2\n";
            phi[4].push_back(ltTwinMuxOut_phi->at(i));
            phi[5].push_back(ltSimTwinMuxOut_phi->at(i));
            break;
            case -1:
            clog<<"caso-1\n";
            phi[6].push_back(ltTwinMuxOut_phi->at(i));
            phi[7].push_back(ltSimTwinMuxOut_phi->at(i));
            break;
            case -2:
            clog<<"caso-2\n";
            phi[8].push_back(ltTwinMuxOut_phi->at(i));
            phi[9].push_back(ltSimTwinMuxOut_phi->at(i));
            break;
            default:
            break;

          }

        }






        
        

      }
      else 
      continue;
   }
    TGraph* g1 = new TGraph(phi[0].size(),phi[0].data(),phi[1].data());
    TGraph* g2 = new TGraph(phi[2].size(),phi[2].data(),phi[3].data());
    TGraph* g3 = new TGraph(phi[4].size(),phi[4].data(),phi[5].data());
    TGraph* g4 = new TGraph(phi[6].size(),phi[6].data(),phi[7].data());
    TGraph* g5 = new TGraph(phi[8].size(),phi[8].data(),phi[9].data());
    c3->cd(1);
    g1->Draw("AP");
    c3->cd(2);
    g2->Draw("AP");
    c3->cd(3);
    g3->Draw("AP");
    c3->cd(4);
    g4->Draw("AP");
    c3->cd(5);
    g5->Draw("AP");
}

void ZMuSkimTree::PhiWheelDist(short w) 
{
  if (abs(w)>2) return;
  if (fChain == 0) return;
  Long64_t nentries = fChain->GetEntriesFast();
  //if (maxentries>-1) nentries=maxentries;
  vector<float> phi[2];
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) 
    {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      clog << jentry << endl;
      //nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      fChain->SetBranchStatus("*",0); 
      fChain->SetBranchStatus("ltSimTwinMuxOut_phi",1);
      fChain->SetBranchStatus("ltTwinMuxOut_phi",1);
      fChain->SetBranchStatus("ltTwinMuxOut_wheel",1);
      fChain->SetBranchStatus("ltTwinMuxOut_sector",1);
      fChain->SetBranchStatus("ltTwinMuxOut_station",1);
      fChain->SetBranchStatus("ltSimTwinMuxOut_wheel",1);
      fChain->SetBranchStatus("ltSimTwinMuxOut_sector",1);
      fChain->SetBranchStatus("ltSimTwinMuxOut_station",1);

      if (ltSimTwinMuxOut_phi->size()== ltTwinMuxOut_phi->size())
      {
        for (unsigned int i = 0; i < ltSimTwinMuxOut_phi->size(); ++i)
        {

          if (ltSimTwinMuxOut_wheel->at(i) == w)
          {
            phi[0].push_back(ltTwinMuxOut_phi->at(i));
            phi[1].push_back(ltSimTwinMuxOut_phi->at(i));
          }


          else
          continue;



        }







      }
      else
        continue;

      





    }

    TGraph* g1 = new TGraph(phi[0].size(),phi[0].data(),phi[1].data());
      g1->Draw("AP");

}

void ZMuSkimTree::PhiWheelDist(short w, short se) {}
void ZMuSkimTree::PhiWheelDist(short w, short se , short sc) {}

void ZMuSkimTree::PhiDiff()
{/*
    DISTRIBUZIONE DIFFERENZE NELLE PHI
  if (fChain == 0) return;

    Long64_t nentries = fChain->GetEntriesFast();
   //if (maxentries>-1) nentries=maxentries;
    vector<float> phi[10];
    TCanvas* c3 = new TCanvas("c3","c3");
    //TCanvas* c2 = new TCanvas("c2","c2");
    c3->Divide(3,2);

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) 
   {
      clog <<"jentry" << jentry << endl;
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      fChain->SetBranchStatus("*",0); 
      fChain->SetBranchStatus("ltSimTwinMuxOut_phi",1);
      fChain->SetBranchStatus("ltTwinMuxOut_phi",1);
      fChain->SetBranchStatus("ltTwinMuxOut_wheel",1);
      fChain->SetBranchStatus("ltTwinMuxOut_sector",1);
      fChain->SetBranchStatus("ltTwinMuxOut_station",1);
      fChain->SetBranchStatus("ltSimTwinMuxOut_wheel",1);
      fChain->SetBranchStatus("ltSimTwinMuxOut_sector",1);
      fChain->SetBranchStatus("ltSimTwinMuxOut_station",1);

      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      
      if (ltSimTwinMuxOut_phi->size()== ltTwinMuxOut_phi->size())
      {
        if 





*/

}
 