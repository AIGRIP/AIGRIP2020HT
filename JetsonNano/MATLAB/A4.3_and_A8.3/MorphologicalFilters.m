function[errorNoImage,segmentationMask] = MorphologicalFilters(colourSegmentationMask, centerOfObjectX, centerOfObjectY)

%The function takes in a binary image where the colours have been segmentated 
%and a rough postion of the object in the image that should be segmented. 
%and it outputs a a bitmask of the the object.

%Input:
%colourBalancedImage = Binary map 984x740
%centerOfObjectX = Objects center postion in the x-axis
%centerOfObjectY = Objects center postion in the y-axis

%Output:
%SegmentationMask = Binary map 984x740 of the object

errorNoImage = 0;

%Fill up the hole in the binary image.
maskFill =imfill(colourSegmentationMask,'holes');


%Get the data about the different blobs in the image
stats = regionprops(maskFill,'Area','Centroid','PixelIdxList');

%Transform the Area and Centroid struct fields into arrays
area = [stats.Area]';
[numRegions,~] = size(area);
centroid = reshape([stats.Centroid],[2,numRegions])';

% Set all blobs that are smaller then 250 pixels to NaN
centroid(:,1) = centroid(:,1) .* (area > 250);
centroid(:,2) = centroid(:,2) .* (area > 250);
centroid(centroid == 0) = NaN;



%Calculate which centroid is closest to the object
distances = sqrt(sum(bsxfun(@minus, centroid, [centerOfObjectY,centerOfObjectX]).^2,2));
[~, index] = min(distances);

%Do an new binary map with only the choosen blob
segmentationMask = zeros(size(colourSegmentationMask),'logical');
segmentationMask(stats(index).PixelIdxList) = 1;

% Make smother edges in the image.
segmentationMask = imerode(segmentationMask,ones(20));
segmentationMask = imdilate(segmentationMask,ones(20));

% Edge filter, display only the edges of the filter.
segmentationMask = MorphologicalEdgeFilter(segmentationMask);

%Check if there is a big enough object in the image
if sum(segmentationMask,'all') < 250
    errorNoImage = 1;
end

end









