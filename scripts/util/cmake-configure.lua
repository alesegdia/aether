function cmakeConfigureFileImmediate(inputFilePath, values)
    local t = {}
    for k,v in pairs(values) do
        t[v] = 1
    end
    cmakeConfigureFile(inputFilePath, t)
end

function cmakeConfigureFile(inputFilePath, refTable)
    if refTable == nil then
        refTable = _G
    end
    local outputFilePath = nil
    for k,_ in string.gmatch(inputFilePath, "(.+).cmake") do
        outputFilePath = k
    end
    local inputFile = io.open(inputFilePath, "r")
    local outputFile = io.open(outputFilePath, "w")
    for line in inputFile:lines() do
        local cmakeDefineFound = nil
        local lcopy = line
        for k,v in line:gmatch("#cmakedefine ([%w_]+)") do
            cmakeDefineFound = k
        end
        local newLine = ""
        if cmakeDefineFound ~= nil then
            if refTable[cmakeDefineFound] == nil then
                newLine = "/* #undef " .. cmakeDefineFound .. " */"
            else
                newLine = "#define " .. cmakeDefineFound
            end
        else
            newLine = lcopy
        end
        outputFile:write("\n" .. newLine)
    end
    inputFile:close()
    outputFile:flush()
    outputFile:close()
end

function copyFile(inFile, outFile)
    infile = io.open(inFile, "r")
    instr = infile:read("*a")
    infile:close()

    outfile = io.open(outFile, "w")
    outfile:write(instr)
    outfile:close()
end