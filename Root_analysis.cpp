#include <fstream>

#include "TCanvas.h"
#include "TF1.h"
#include "TGraph.h"

void graphics() {
  // BX FILE
  std::ifstream if1("Bx.txt");
  std::vector<double> x1_values, y1_values;

  double x1, y1;
  while (if1 >> x1 >> y1) {
    x1_values.push_back(x1);
    y1_values.push_back(y1);
  }
  if1.close();

  TGraph *grBx = new TGraph(x1_values.size(), x1_values.data(), y1_values.data());
  //grBx->SetMarkerStyle(8);

  // By FILE
  std::ifstream if2("Bx.txt");
  std::vector<double> x2_values, y2_values;

  double x2, y2;
  while (if2 >> x2 >> y2) {
    x2_values.push_back(x2);
    y2_values.push_back(y2);
  }
  if2.close();

  TGraph *grBy = new TGraph(x2_values.size(), x2_values.data(), y2_values.data());
  //grBy->SetMarkerStyle(8);

  // BZ FILE
  std::ifstream if3("Bx.txt");
  std::vector<double> x3_values, y3_values;

  double x3, y3;
  while (if3 >> x3 >> y3) {
    x3_values.push_back(x3);
    y3_values.push_back(y3);
  }
  if3.close();

  TGraph *grBz = new TGraph(x3_values.size(), x3_values.data(), y3_values.data());
  //grBz->SetMarkerStyle(8);

  // TF1* func= new TF1("func", "[0]/((1-x))");
  // func->SetParameters(1);
  // graph->Fit(func, "Q");
  // std::cout<<"Parameter: "<<func->GetParameter(0)<<'\n';
  // std::cout<<"reduced chi: "<<func->GetChisquare()/func->GetNDF()<<'\n';
  // std::cout<<"fit prob: "<<func->GetProb()<<'\n';

  TCanvas *canvas = new TCanvas("canvas", "Graph", 800, 600);
//   canvas->Divide(3, 1);
//   canvas->cd(1);
//   grBx->Draw("AP");
//   // func->Draw("SAME");

//   canvas->cd(2);
  grBy->Draw("AP");

//   canvas->cd(3);
//   grBz->Draw("AP");

  canvas->Draw();
}