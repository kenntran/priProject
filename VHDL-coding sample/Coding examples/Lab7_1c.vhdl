LIBRARY ieee ;
USE ieee.std_logic_1164.all ;
use IEEE.NUMERIC_STD.all;
use IEEE.std_logic_unsigned.all;

ENTITY Lab7_1c IS
PORT (J,K,R,S: IN STD_LOGIC;
Q: OUT STD_LOGIC );
END Lab7_1c;

ARCHITECTURE JKFlipFlop OF Lab7_1c IS
signal state : std_logic;
constant PERIOD: time := 50ns;
signal clk : std_logic := '0';
BEGIN
P0:PROCESS(J,K,R,S,clk) 
BEGIN
clk <= not clk after PERIOD/2;
IF(S = '0') then
	state <= '1';
ELSIF(R = '0') then
	state <= '0';
ELSIF rising_edge(clk) THEN				
	IF( (J OR K) = '0' ) THEN 			
		state <= state;
	
	ELSIF(J = '1' AND K = '1') THEN			
		state <= not state;
	
	ELSE 
		IF(K = '1') THEN
			state <= '0';
		ElSIF(J = '1') THEN
			state <= '1';
		END IF;
	END IF;
ELSIF falling_edge(clk) THEN
	Q <= state;

END IF;
END PROCESS P0;

END JKFlipFlop;

