function add(a, b)
	return a+b
end

function divide(a,b)
	if b == 0 then
		return 0
	end
	
	return a/b
end

print(add(5,6))
print(divide(7,0))