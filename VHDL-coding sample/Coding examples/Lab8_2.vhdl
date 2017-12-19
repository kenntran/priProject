LIBRARY ieee ;
USE ieee.std_logic_1164.all ;
use IEEE.NUMERIC_STD.all;
use IEEE.std_logic_unsigned.all;

ENTITY Lab8_2 IS
PORT (UD,rst: IN STD_LOGIC;
Q: OUT STD_LOGIC_VECTOR(1 DOWNTO 0));
END Lab8_2;

ARCHITECTURE BitCounter OF Lab8_2 IS
constant PERIOD: time := 50ns;
signal clk : std_logic := '0';
signal tmp:STD_LOGIC_VECTOR (1 downto 0);
BEGIN
P0:PROCESS(rst,UD,clk) 
BEGIN
clk <= not clk after PERIOD/2;			-- Generating clock, the period = 50ns. 
IF(rst = '1') then
	 tmp<="00";
ELSIF (clk'event and clk='1') THEN				
	IF( UD = '1' ) THEN 			 
		tmp <= tmp + 1;
	
	ELSE			
		tmp <= tmp - 1;
	
	END IF;	

END IF;
END PROCESS P0;
Q <= tmp;
END BitCounter;

