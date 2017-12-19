LIBRARY ieee ;
USE ieee.std_logic_1164.all ;
use IEEE.NUMERIC_STD.all;
use IEEE.std_logic_unsigned.all;

ENTITY Lab7_2 IS
PORT (T,R,S: IN STD_LOGIC;
Q: OUT STD_LOGIC);
END Lab7_2;

ARCHITECTURE JKFlipFlop OF Lab7_2 IS
signal state : std_logic := '0';
constant PERIOD: time := 50ns;
signal clk : std_logic := '0';
BEGIN
P0:PROCESS(T,R,S,clk) 
BEGIN
clk <= not clk after PERIOD/2;
IF(S = '0') then
	state <= '1';
ELSIF(R = '0') then
	state <= '0';
ELSIF rising_edge(clk) THEN				
	IF( T = '0' ) THEN 			 
		state <= state;
	
	ELSIF(T = '1') THEN			
		state <= not state;
	
	END IF;	

END IF;
END PROCESS P0;
Q <= state;
END JKFlipFlop;

