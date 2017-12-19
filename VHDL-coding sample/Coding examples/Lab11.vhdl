LIBRARY ieee ;
USE ieee.std_logic_1164.all ;
use ieee.numeric_std.all; 
use IEEE.std_logic_unsigned.all;

ENTITY Lab11 IS
PORT (A, B, S: IN STD_LOGIC_VECTOR (3 DOWNTO 0) ; 
M,CLR: IN STD_LOGIC;
F: OUT STD_LOGIC_VECTOR (3 DOWNTO 0));
END Lab11;

ARCHITECTURE Arithmetic OF Lab11 IS
signal z: std_logic_vector(3 DOWNTO 0) := "0000";
BEGIN

opera_proc: process(M, A, B, S)
begin 

if(CLR = '1') then
	F <= "0000";
end if;

	case M is 
		when '1' =>					-- items regarding state ST0
			
			case S is 
				when "0000" => F <= not A;
				when "0001" => F <= not (A or B);
				when "0010" => F <= (not A) and B;
				when "0011" => F <= "0000";
				when "0100" => F <= not (A and B);
				when "0101" => F <= not B;
				when "0110" => F <= A xor B;
				when "0111" => F <= A and (not B);
				when "1000" => F <= (not A) or B;
				when "1001" => F <= not (A xor B);
				when "1010" => F <= B;
				when "1011" => F <= A and B;
				when "1100" => F <= "0001";
				when "1101" => F <= A or (not B);
				when "1110" => F <= A or B;
				when "1111" => F <= A;
				
				when others => F <= "0000";
			end case;

		when '0' =>					-- items regarding state ST1
			
			case S is 
				when "0000" => F <= A;
				when "0001" => F <= A or B; 
				when "0010" => F <= A or (not B);
				when "0011" => F <= std_logic_vector(unsigned((not z) + 1)) - 1 ;  	--F output = 0000 (2's complement) - 1 
				when "0100" => F <= A + (A and (not B));
				when "0101" => F <= (A or B) + (A and (not B));
				when "0110" => F <= (A - B) - 1; 
				when "0111" => F <= (A and (not B)) - 1;
				when "1000" => F <= A + (A and B); 
				when "1001" => F <= A + B;
				when "1010" => F <= (A or (not B)) + (A and B);
				when "1011" => F <= (A and B) - 1;
				when "1100" => F <=  A + (std_logic_vector(unsigned(A) sll 1)); 
				when "1101" => F <= (A or B) + A;
				when "1110" => F <= (A or not(B)) + A;
				when "1111" => F <= A - 1;
				
				when others => F <= "0000";
			end case;

		when others =>					-- the catch-all condition
			F <= "0000";
	end case;
end process opera_proc;
end Arithmetic;