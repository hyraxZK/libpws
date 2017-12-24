#pragma once

#include <vector>
#include <map>

#include "pws_circuit_parser.hh"
#include "cmt_circuit.hh"
#include "cmt_circuit_builder.hh"

class PWSCircuit : public CMTCircuit
{
  private:
  PWSCircuitParser& parser;

  public:
  PWSCircuit(PWSCircuitParser& pp);

  Gate getGate(const GatePosition& pos);
  CircuitLayer& getGatePosLayer(int gatePosLayer);
  void evalGates(const std::vector<int>& start);
  void evalGates(const std::vector<int>& start, const std::vector<int>& end);
  virtual void evaluate();

  virtual void initializeInputs(const MPQVector& inputs, const MPQVector& magic = MPQVector(0));
  virtual void initializeOutputs(const MPQVector& outputs);

  protected:
  virtual void constructCircuit();

  private:
  void makeGateMapping(std::vector<Gate*>& gates, CircuitLayer& layer, const std::vector<int>& mapping);
  void makeGateMapping(std::vector<Gate*>& gates, CircuitLayer& layer, const std::map<int, int>& mapping, int offset);
};

class PWSCircuitBuilder : public CMTCircuitBuilder
{
  PWSCircuitParser& parser;

  public:
  PWSCircuitBuilder(PWSCircuitParser& pp);

  PWSCircuit* buildCircuit();
};
