function myfunction ()
    n = n/nil
end

function myerrorhandler( err )
    print("ERROR:")
    print(err)
    print("End Error")
end

-- 

if pcall(myfunction) then
    print("Success")
else
	print("Failure")
end

status = xpcall( myfunction, myerrorhandler )
print( status)