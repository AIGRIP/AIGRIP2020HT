function [edgeBinaryImage] = MorphologicalEdgeFilter(inputBinaryImage)
%MorphologicalEdgeFilter run an morpological edge filter on the input image
%and return an image with only edges.
%   inputBinaryImage - Should be an binary image.
%   edgeBinaryImage  - returns a binary edge image.

    % Set the edge as high and all high pixels inside the object low.
    edgeBinaryImage = inputBinaryImage & ~imerode(inputBinaryImage,ones(3) );
end

